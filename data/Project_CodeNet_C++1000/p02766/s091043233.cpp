#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N, K, T, ans;
  cin >> N >> K;
  T=1;
  ans=0;
  for (int i=0; i<40; i++) {
    if (N>=T) {
      ans=ans+1;
      T=T*K;
    }
  }
  cout << ans << endl;
}