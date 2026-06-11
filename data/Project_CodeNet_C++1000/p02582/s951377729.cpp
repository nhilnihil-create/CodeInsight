#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int count = 0;
  
  for (int i = 0; i < 3; i++) {
    if (S.at(i) == 'R') {
      count ++;
    }
  }
  
  if (count == 2) {
    if (S.at(1) == 'S') {
      count = 1;
    } 
  }
  cout << count << endl;
}