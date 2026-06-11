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

const long long MOD = 1000000007;

int main() {
  long long N, K;
  cin >> N >> K;
  long long ans = 0;
  long long dp[100001];
  for(long long i = K; i >= 1; i--) {
    long long a = K / i;
    long long t = N;
    long long temp = 1;
    while(t > 0) {
      if(t & 1) {
        temp = temp * a;
        temp %= MOD;
      }
      a = a * a % MOD;
      t >>= 1;
    }
    // cout << temp << endl;
    for(long long j = i+i; j <= K; j+=i) {
      temp -= dp[j];
    }
    dp[i] = temp;
  }

  rep(i, K) {
    ans += dp[i+1] * (i+1);
    ans %= MOD;
  }

  cout << ans << endl;
  return 0;
}