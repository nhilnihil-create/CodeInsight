#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  string S;
  cin>>S;
  ll N = S.size();
  reverse(S.begin(),S.end());
  vector<vector<ll>> dp(N,vector<ll>(13,0));
  ll cnt = 1;
  for(ll i = 0; i < N; i++){
    if(i==0){
      if(S[i]=='?') {
        for(ll j = 0; j < 10LL;j++) dp[i][j]++;
      }
      else {
        ll t = S[i]-'0';
        dp[i][t]++;
      }
    }
    else{
      if(S[i]=='?'){
        for(ll j = 0; j < 10LL; j++){
          for(ll k = 0; k < 13LL; k++){
            dp[i][(k+cnt*j)%13]=(dp[i][(k+cnt*j)%13]+dp[i-1][k])%mod;
          }
        }
      }
      else{
        ll t = S[i]-'0';
        for(ll j = 0; j < 13; j++){
          dp[i][(j+t*cnt)%13]=(dp[i][(j+t*cnt)%13]+dp[i-1][j])%mod;
        }
      }
    }
    cnt = (cnt*10LL)%13LL;
  }
  cout<<dp[N-1][5]<<endl;
}