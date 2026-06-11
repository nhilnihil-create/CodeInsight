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
using P = pair<double, double>;

int main() {
  int N;
  int K;
  double a[200001];
  cin >> N >> K;
  a[0] = 0;
  rep(i, N) {
    cin >> a[i+1];
  }
  rep(i, N) {
    a[i+1] += a[i];
  }
  double b[200000];
  rep(i, N+1-K) {
    b[i] = a[i+K] - a[i];
  }
  double ans = 0;
  rep(i, N+1-K) {
    ans = max(ans, b[i]);
  }
  ans = (ans + K) / 2;
  cout << std::setprecision(8) << std::fixed << ans << endl;
  return 0;
}