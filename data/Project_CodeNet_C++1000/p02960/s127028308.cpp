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

#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using P = pair<long long, long long>;

const long long MOD = 1e9 + 7;
long long dp[100001][13] = {0};
long long M[100000];

int main() {
  M[0] = 1; 
  for(long long i = 0; i < 99999; i++) {
    M[i+1] = (M[i] * 10) % 13;
  }
  string S;
  cin >> S;
  if(S[S.size()-1] == '?') {
    for(long long i = 0; i < 10; i++) {
      dp[1][i] = 1;
    }
  } else {
    dp[1][S[S.size()-1] - '0'] = 1;
  }

  for(long long key = 1; key <= S.size()-1; key++) {
    long long i = (S.size() - key - 1);
    if(S[i] != '?') {
      long long temp = S[i] - '0';
      for(long long j = 0; j < 13; j++) {
        long long t = (temp * M[key] + j) % 13;
        dp[S.size()-i][t] += dp[S.size()-i-1][j];
        dp[S.size()-i][t] %= MOD;
      }
    } else {
      rep(k, 13) {
        rep(j, 10) {
          long long temp = j;
          long long t = (temp * M[key] + k) % 13;
          dp[S.size()-i][t] += dp[S.size()-i-1][k];
          dp[S.size()-i][t] %= MOD;
        }
      }
    }
  }

  cout << dp[S.size()][5] << endl;

  return 0;
}