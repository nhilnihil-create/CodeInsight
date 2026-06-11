#include <iostream>
#include <string>
using namespace std;

int main() {

  string S;
  cin >> S;

  char c_3 = S[2];
  char c_4 = S[3];
  char c_5 = S[4];
  char c_6 = S[5];

  int N = 0;
  if (c_3 == c_4) {
    N++;
  }
  if (c_5 == c_6) {
    N++;
  }

  if (N == 2) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
  
  return 0;
}
