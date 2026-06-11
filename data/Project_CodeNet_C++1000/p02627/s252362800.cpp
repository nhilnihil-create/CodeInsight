#include <bits/stdc++.h>
using namespace std;
int main() {
  char A;
  cin >> A;
  int c = 0;
  string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for(int i = 0; i < 26; i++) {
    if(A == ALP.at(i)) {
      cout << "A" << endl;
      c++;
    }
  }
  if(c == 0) {
    cout << "a" << endl;
  }
}
