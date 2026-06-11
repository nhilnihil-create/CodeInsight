#include<bits/stdc++.h>
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
using ll = long long;
using P = pair<int, int>;
using MATRIX = vector< vector<ll> >;

int main() {
  int N, L;
  cin >> N >> L;
  int ans = (2 * L + N - 1) * N / 2;
  if(L > 0) {
    cout << ans - L << endl;
    return 0;
  }
  if(N + L - 1 < 0) {
    cout << ans - (L + N - 1) << endl;
    return 0;
  }
  cout << ans << endl;
  return 0;
}