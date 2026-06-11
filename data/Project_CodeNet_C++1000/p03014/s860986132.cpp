

#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll INF=1e18;




int main() {
  ll h,w;
  cin >> h>>w;
  vector<string> s(h);
  rep(i,h)cin>>s[i];
  vector<vector<ll>> l(h+5, vector<ll> (w+5,0));
  vector<vector<ll>> r(h+5, vector<ll> (w+5,0));
  vector<vector<ll>> u(h+5, vector<ll> (w+5,0));
  vector<vector<ll>> d(h+5, vector<ll> (w+5,0));


  rep(i,h){
    rep(j,w){
      if (s[i][j]=='.'){
        u[i+1][j+1]=u[i][j+1]+1;
        l[i+1][j+1]=l[i+1][j]+1;
      }
    }
  }
  rep(i,h){
    rep(j,w){
      if (s[h-1-i][w-1-j]=='.'){
        d[h-i][w-j]=d[h-i+1][w-j]+1;
        r[h-i][w-j]=r[h-i][w-j+1]+1;
      }
    }
  }
  ll ans=0;
  rep(i,h)rep(j,w){
  //  cout<<"i"<<i<<"j"<<j<<endl;
    ll temp=l[i+1][j+1]+r[i+1][j+1]+u[i+1][j+1]+d[i+1][j+1];
  //  cout<<temp<<endl;
    ans=max(ans,l[i+1][j+1]+r[i+1][j+1]+u[i+1][j+1]+d[i+1][j+1]-3);
  }

cout<<ans;
}
