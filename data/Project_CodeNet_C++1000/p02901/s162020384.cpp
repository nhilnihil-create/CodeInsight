#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll MOD = 1000000007;
const ll INF = 10000000000000;
#define all(v) v.begin(), v.end()

int main(){
  ll N,M;
  cin >> N >> M;
  vector<vector<ll>> dp(M,vector<ll>((ll)pow(2,N),INF));
  rep(i,M) dp.at(i).at(0)=0;
  rep(i,M){
    ll a,b;
    cin >> a >> b;
    vector<ll> c(b);
    rep(j,b) cin >> c.at(j);
    ll t=0;
    rep(j,b){
      t+=(ll)pow(2,c.at(j)-1);
    }
    if(i==0){
      dp.at(i).at(t)=a;
      continue;
    }
    rep(j,(ll)pow(2,N)){
      dp.at(i).at(j)=min(dp.at(i).at(j),dp.at(i-1).at(j));
      if(t!=j){
        dp.at(i).at(t|j)=min(dp.at(i).at(t|j),dp.at(i-1).at(j)+a);
      }
    }
  }
  if(dp.at(M-1).at((ll)pow(2,N)-1)==INF){
    cout << -1 << endl;
  }else{
    cout << dp.at(M-1).at((ll)pow(2,N)-1) << endl;
  }
}