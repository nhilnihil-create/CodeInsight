#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  string S;
  int s;
  cin >> S;
  s=S.size();
  if (s==1) {
    cout << 'x' << endl;
  }
  else {
    for (int i=0; i<s-1; i++) {
      cout << 'x';
    }
    cout << 'x' << endl;
  }
}