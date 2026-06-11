#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<typename T> bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<typename T> bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef tuple<ll,ll,ll> tlll;
typedef tuple<int,int,int> tiii;
const ll mod=1e9+7;
const int inf=1<<30;

ll dp[2010][2010];

int main(){
  int n; cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  vector<pll> v(0);
  rep(i,n){
    v.emplace_back(a[i],i);
  }
  sort(all(v));
  reverse(all(v));
  ll ans=0;
  rep(i,n)for(int j=0;j<=i;j++){
    chmax(dp[i+1][j],dp[i][j]+v[i].first*abs(v[i].second-((n-1)-(i-j))));
    chmax(dp[i+1][j+1],dp[i][j]+v[i].first*abs(v[i].second-j));
  }
  rep(j,n+1){
    chmax(ans,dp[n][j]);
  }
  /*
  rep(i,n+1){
    rep(j,n+1){
      cout << dp[i][j];
    }cout << endl;
  }*/
  cout << ans << endl;
}