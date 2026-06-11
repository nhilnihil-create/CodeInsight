#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N, ans;
  string S;
  cin >> N >> S;
  ans=0;
  for (int i=0; i<N-2; i++) {
    if (S.at(i)=='A' && S.at(i+1)=='B' && S.at(i+2)=='C') {
      ans=ans+1;
    }
  }
  cout << ans << endl;
}