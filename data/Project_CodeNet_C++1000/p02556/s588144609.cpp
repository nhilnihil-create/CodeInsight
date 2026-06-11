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
template <class T> inline bool chmin(T &x, const T &y) {if (x > y) {x = y; return 1;} return 0;}
template <class T> inline bool chmax(T &x, const T &y) {if (x < y) {x = y; return 1;} return 0;}

int main() {
  int N;
  int x[200000], y[200000];
  cin >> N;
  rep(i, N) {
    cin >> x[i] >> y[i];
  }
  int z[20000], w[200000];
  rep(i, N) {
    z[i] = x[i] + y[i];
    w[i] = x[i] - y[i];
  }
  sort(z, z + N);
  sort(w, w + N);
  int ans = 0;
  ans = max(z[N-1] - z[0], w[N-1] - w[0]);
  cout << ans << endl;
  return 0;
}