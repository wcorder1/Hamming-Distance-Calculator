 #include <iostream>
 #include <string>
using namespace std;

string toBinary(int x) { //method to convert integer to binary string
  string bin = "";
  while (x > 0) {     
    if ((x%2) == 0) { //adds 0 to binary string if no remainder
      bin.push_back('0');
    }
    else if ((x%2) == 1) { //adds 1 to binary string if remainder
      bin.push_back('1');
    }
    else bin.push_back('0');
    x = x/2;
  }
  string bin2 = "";
  int y = bin.length(); //defines integer for binary string's length
  for (y - 1; y >= 0; y--) { //for loop to reverse string
    bin2.push_back(bin[y]); //adds reversed binary string of bin to new string bin2
  }
  return bin2; //sets value of function to string bin2
}


int hamming(string a, string b) { //method to compare strings for hamming distance (only works after lengths are same)
  int ham = 0;
  int x = a.length();
  for (x; x >= 0; x--) { //for loop iterating the length of the string
    if (a[x] != b[x]) { //if statement comparing the individual lengths of string a and b
      ham++; //adds 1 to ham number for every difference
    }
    else if (a[x] = b[x]) {
      ham + 0;
    }
  }
  return ham;
}


int main(int argc, char* argv[]) {
  for (int i = 0; i < argc; ++i); //basic command line argument

  int num1 = atoi(argv[2]);
  int num2 = atoi(argv[3]); //uses string method (atoi) to convert constant chars to int from command line arguments

  string bin1 = toBinary(num1);
  string bin2 = toBinary(num2);

  int x = bin1.length();
  int y = bin2.length();

  if (x > y) { //case for if first binary is larger
    int i = 0;
    int z = x - y;
    for (z; z > 0; z--) {
      i++;
      bin2.insert(i,1,'0');
    }
  }
  else if (y > x) { //case for if second binary is larger
    int i = 0;
    int z = y - x;
    for (z; z > 0; z--) { //for loop that uses the difference in binary lengths to iterate 0's
                          //being inserted at start of string
      i++;
      bin1.insert(i,1,'0');
    }
  }
  else if (x = y) { //default case if binary strings are equal length
    bin1 = bin1;
    bin2 = bin2;
  }
  
  cout << bin1 << " is the bit string for " << num1 << endl;
  cout << bin2 << " is the bit string for " << num2 << endl;
  cout << hamming(bin1,bin2) << " is the Hamming distance between the bit strings" << endl;
}


