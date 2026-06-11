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

#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using P = pair<long long, long long>;

long long dp[2000][2000] = {0};

int main() {
  long long N;
  cin >> N;
  P b[2000];
  rep(i, N) {
    long long temp;
    cin >> temp;
    b[i] = {temp, i+1};
  }
  P a[2000];
  sort(b, b+N);

  rep(i, N) {
    a[i] = b[N-i-1];
  }

  for(long long k = 0; k < N; k++) {
    for(long long x = 0; k - x >= 0; x++) {
      long long y = k - x;
      dp[x+1][y] = max(dp[x+1][y], dp[x][y] + a[x+y].first * abs(a[x+y].second - x-1));
      dp[x][y+1] = max(dp[x][y+1], dp[x][y] + a[x+y].first * abs(a[x+y].second - N + y));
    }
  }
  // for(long long k = 0; k <= N; k++) {
  //   for(long long x = 0; k - x >= 0; x++) {
  //     long long y = k - x;
  //     cout << dp[x][y] << " ";
  //   }
  //   cout << endl;
  // }
  long long ans = 0;
  rep(i, N+1) {
    long long j = N - i;
    ans = max(ans, dp[i][j]);
  }
  cout << ans << endl;
  return 0;
}