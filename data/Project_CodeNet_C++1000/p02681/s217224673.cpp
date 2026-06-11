#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  int s, k;
  s=S.size();
  k=0;
  for (int i=0; i<s; i++) {
    if (S.at(i)==T.at(i)) {
      k=k+1;
    }
  }
  if (k==s) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}