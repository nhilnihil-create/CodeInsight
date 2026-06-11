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
using ll = long long;
using P = pair<long long, long long>;
using MATRIX = vector< vector<ll> >;

const long long MAX = 510000;
const long long MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (long long i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(long long n, long long k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

long long N, K;
long long M;

int main() {
  COMinit();
  cin >> N >> K;
  M = N - K;
  long long sum[100000];
  sum[0] = 0;
  for(long long i = 1; i <= K; i++) {
    long long temp = COM(M + i, M) * COM(K-1, i-1);
    // cout << "bef " << temp << endl;
    temp %= MOD;
    for(int j = 1; j <= i-1; j++) {
      temp -= (sum[j] * COM(K-j, i-j)) % MOD;
      if(temp < 0) temp += MOD;
    }
    sum[i] = temp;
    sum[i] %= MOD;
    cout << temp << endl;
  }
  return 0;
}