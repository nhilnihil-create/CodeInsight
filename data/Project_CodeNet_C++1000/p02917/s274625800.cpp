#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
#include<bitset>
#include<iomanip>
#include<queue>
#include<functional>
#include<stack>
#include<tuple>
#include<cassert>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using P = pair<int, int>;

int main() {
  int n;
  int a[100];
  int b[100];
  cin >> n;
  rep(i, n - 1) {
    cin >> b[i];
  }

  int ans = 0;
  a[0] = b[0];
  for(int i = 1; i < n - 1; i++) {
    a[i] = min(b[i-1], b[i]);
  }
  a[n-1] = b[n-2];
  rep(i, n) {
    ans += a[i];
  }
  cout << ans << endl;
  return 0;
}