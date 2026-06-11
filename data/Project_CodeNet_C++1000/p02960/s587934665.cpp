#include <stdio.h>
#include <vector>
#include <iostream>
#include <queue>
#include <bits/stdc++.h>
 
#define rep(i,n) for (int i=0;i<(n);++i)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef pair<int, int> pi;

const ll MOD = 1e9 + 7;

int main() {
  string s;
  cin >> s;

  reverse(s.begin(), s.end());
  int n = s.size();
  vector<ll> dp(13, 0);
  dp[0] = 1;

  ll keta = 1;
  rep(is, n){
    vector<ll> new_dp(13, 0);
    if (s[is] == '?'){
      rep(i, 10){
        int m = (keta * i) % 13;
        rep(j, 13){
          int ni = (j + m) % 13; 
          new_dp[ni] += dp[j];
          new_dp[ni] %= MOD;
        }
      }
    }else{
      ll idx = (s[is] - '0') * keta;
      rep(i, 13){
        new_dp[(i+idx) % 13] = dp[i];
      }
    }

    dp = new_dp;
    keta *= 10; keta %= 13;
  }
  cout << dp[5] << endl;
  return 0;
}