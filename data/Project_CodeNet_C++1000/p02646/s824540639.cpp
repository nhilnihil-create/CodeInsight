#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i<(n);i++)
#define fore(i,a) for(auto &i:a)
#define debug(a,b) cout << "debug : " << a << " , "<< b << endl
using ll=long long;
const ll INF=1LL<<60;
const ll mod=1E9+7;


int main(){
  ll a,b,v,w,t;
  cin >> a >> v >> b >> w >> t;
  ll A,V;
  A=max(a,b)-min(a,b);
  V=max(v,w)-min(v,w);
  if(w-v>=0)cout << "NO";
  else if(V*t>=A)cout << "YES";
  else cout << "NO";
}
