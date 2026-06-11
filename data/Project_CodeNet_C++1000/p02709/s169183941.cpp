#include <bits/stdc++.h>

using namespace std;

void max_self(long long& a , long long b){
  a = max(a , b);
}

int main() {
  int n ; cin>>n;
  vector<pair<long long, int> > v;
  for(int i = 0 ; i < n; ++i){
    long long x ; cin>>x;
    v.emplace_back(x , i);
  }
  sort(v.rbegin() , v.rend());
  vector<vector<long long> > dp(n + 1 , vector<long long>(n + 1 , -1000000000 - 9));
  dp[0][0] = 0;
  for(int i = 0 ; i < n; ++i){
    int p = v[i].second;
    for(int j = 0 ; j <= i; ++j){
      max_self(dp[i + 1][j + 1] , dp[i][j] + abs(p - j) * v[i].first);
      max_self(dp[i + 1][j] , dp[i][j] + abs(n - 1 - (i - j) - p) * v[i].first);
    }
  }
  long long ans = 0;
  for(int i = 0 ; i <= n; ++i){
    max_self(ans , dp[n][i]);
  }
  cout<<ans<<"\n";
}