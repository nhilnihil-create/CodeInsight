#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  string S;
  cin >> S;
  int n, k, m;
  n=S.size();
  k=0;
  if (n%2!=0) {
    cout << "No" << endl;
  }
  else {
    m=n/2;
    for (int i=0; i<m; i++) {
      if (S.at(2*i)=='h' && S.at(2*i+1)=='i') {
        k=k+1;
      }
    }
    if (k==m) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
}