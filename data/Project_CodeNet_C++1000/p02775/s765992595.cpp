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


int main() {
  string ns;
  cin >> ns;
  int n = ns.size();

  ns += '0';
  vi v;
  rep(i, n) v.push_back(ns[i] - '0');
  reverse(v.begin(), v.end());

  int dp[n+2][2];
  dp[0][0] = 0; dp[0][1] = 11;
  rep(i, n+1){
    dp[i+1][0] = min(dp[i][0] + v[i], dp[i][1] + v[i] + 1);
    dp[i+1][1] = min(dp[i][0] + (10 - v[i]), dp[i][1] + (10 - v[i] - 1));
  }
  cout << dp[n+1][0] << endl;
  return 0;
}