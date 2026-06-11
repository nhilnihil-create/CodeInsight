#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  string S, T;
  cin >> S >>T;
  int ans=0;
  for (int i=0; i<3; i++) {
    if (S.at(i)==T.at(i)) {
      ans=ans+1;
    }
  }
  cout << ans << endl;
}