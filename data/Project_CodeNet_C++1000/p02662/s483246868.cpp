#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 998244353LL;

int main() {
  ll N,S;
  cin>>N>>S;
  vector<ll> v(N);
  for(ll i = 0; i < N; i++) cin>>v[i];
  vector<vector<ll>> dp(N,vector<ll>(S+1,0));
  for(ll i = 0; i < N; i++){
    if(i==0) {
      if(v[i]<=S) dp[i][v[i]]=1;
      dp[i][0]=2;
    }
    else{
      for(ll j = 0; j <= S; j++){
        dp[i][j]=(dp[i-1][j]*2)%mod;
        if(j>=v[i]) dp[i][j]=(dp[i][j]+dp[i-1][j-v[i]])%mod;
      }
    }
  }
  cout<<dp[N-1][S]<<endl;
}