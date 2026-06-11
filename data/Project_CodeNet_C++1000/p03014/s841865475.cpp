#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define cvector vector<char>
#define svector vector<string>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define rep(i,n) for(ll i=0; i<n; ++i)
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll h,w;cin>>h>>w;
  vector<string> G(h);rep(i,h) cin>>G[i];
  vector<lvector> V(h,lvector(w,0)),W(w,lvector(h,0));
  rep(i,h) {
    ll v=0,pos=0;
    rep(j,w) {
      if(G[i][j]=='.') v++;
      else {
        fill(V[i].begin()+pos,V[i].begin()+pos+v,v);
        pos=j+1,v=0;
      }
    }
    if(v>0) fill(V[i].begin()+pos,V[i].end(),v);
  }
  rep(i,w) {
    ll v=0,pos=0;
    rep(j,h) {
      if(G[j][i]=='.') v++;
      else {
        fill(W[i].begin()+pos,W[i].begin()+pos+v,v);
        pos=j+1,v=0;
      }
    }
    if(v>0) fill(W[i].begin()+pos,W[i].end(),v);
  }
  ll ans=-1;
  rep(i,h)rep(j,w) ans=max(ans,V[i][j]+W[j][i]);
  print(ans-1);
  return 0;
}