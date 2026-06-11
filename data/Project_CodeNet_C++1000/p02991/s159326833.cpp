
#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
const ll INF=1e18;

vector<ll> g[100005];
ll u[3][100005];



int main() {
  ll n,m;
  cin >> n>>m;
  rep(i,m){
    ll u1,v1;
    cin>>u1>>v1;
    u1--;v1--;
    g[u1].push_back(v1);
  //  g[v1].push_back(u1);

  }
  rep(i,3)rep(j,100005)u[i][j]=-3;
  ll s1,t1;
  cin>>s1>>t1;
  s1--;t1--;
  queue <P> q;
  q.push(make_pair(s1,0));
  while(!q.empty()){
    P now=q.front();
    q.pop();
    ll t=now.first;
    ll dist=now.second;
    for(ll to:g[t]){
      if (u[(dist+1)%3][to]!=-3)continue;
  //    cout<<"to"<<to<<"d"<<(dist+1)<<endl;
      u[(dist+1)%3][to]=dist+1;
      q.push(make_pair(to,dist+1));
    }
  }

cout<<u[0][t1]/3;

}
