#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
  ll n,m;
  cin >> n >> m;
  vector<set<ll>> v(n);
  for(ll i=0;i<m;i++) {
    ll a,b;
    cin >> a >> b;
    a--;
    b--;
    v[a].insert(b);
  }
  ll s,t;
  cin >> s >> t;
  s--;
  t--;
  vector<vector<ll>> dis(n,vector<ll> (3,-1));
  queue<pll> q;
  q.push(pll(s,0));
  dis[s][0]=0;
  while(q.size()) {
    ll f=q.front().first;
    ll d=q.front().second;
    q.pop();
    for(ll t:v[f]) {
      if(dis[t][(d+1)%3]<0) {
        dis[t][(d+1)%3]=d+1;
        q.push(pll(t,d+1));
      }
    }
  }
  if(dis[t][0]<0) {
    cout << -1 << endl;
  }
  else {
    cout << dis[t][0]/3 << endl;
  }
}