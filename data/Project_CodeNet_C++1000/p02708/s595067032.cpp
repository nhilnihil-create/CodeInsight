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
  for(long long i = K; i <= N+1; i++) {
    long long b = i * (N - i + 1);
    b %= MOD;
    b += 1;
    b %= MOD;
    ans += b;
    ans %= MOD;
    // cout << ans << endl;
  }
  cout << ans << endl;
  return 0;
}