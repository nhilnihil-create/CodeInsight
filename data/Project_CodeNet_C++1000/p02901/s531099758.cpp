#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;


const ll INF = 1e18;



int main() {
  ll n, m;
  cin >> n >> m;
  vector<P> c(m);
  vector<ll> p(15);
  ll now=1;
  rep(i,14){
    p[i]=now;
    now*=2;
  }
  rep(i,m){
    ll a1,b1;
    cin>>a1>>b1;
    ll now=0;
    rep(j,b1){
      ll c1;
      cin>>c1;
      c1--;
      now+=p[c1];
    }
    c[i]=make_pair(a1,now);
  }
  ll N=(2<<n);
//  cout<<N<<"N"<<endl;
//  cout<<(13|14)<<endl;
  ll dp[m+5][N+5];
  rep(i,m+5)rep(j,N+5)dp[i][j]=INF;
  rep(i,m+5) dp[i][0]=0;
  rep(i,m){
    rep(j,N){
      ll cost=c[i].first;
      ll key=c[i].second;
      dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
      dp[i+1][j|key]=min(dp[i+1][j|key], dp[i][j]+cost);
    //  cout<<dp[i][j]+cost<<' '<<i<<'i'<<j<<'j'<<' '<<(j|key)<<endl;
    }
  }
//cout<<endl;
  ll ans=INF;
  rep(i,m+1){
    ans=min(ans,dp[i][(2<<(n-1))-1]);
  //  cout<<((2<<(n-1))-1)<<" "<<ans<<endl;
  }
  if (ans==INF)ans=-1;
  cout<<ans;
}
