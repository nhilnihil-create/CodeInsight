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

ll m;
vector<lvector> V;

void gen_increase_series(ll pos,lvector v) {
  if(v.back()>0) V.emplace_back(v);
  else {
    for(ll d=0;d+v[pos]<=m;++d) {
      v[pos+1]=v[pos]+d;
      gen_increase_series(pos+1,v);
    }
  }
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,q,a,b,c,d,ans=-1,ans_;cin>>n>>m>>q;
  lvector e(n,0);e[0]++;
  vector<lvector> v(q);
  rep(i,q) {cin>>a>>b>>c>>d;a--,b--;v[i]=lvector{a,b,c,d};}
  gen_increase_series(0,e);
  for(lvector i:V) {
    ans_=0;
    for(lvector r:v) if(i[r[1]]-i[r[0]]==r[2]) ans_+=r[3];
    ans=max(ans_,ans);
  }
  print(ans);
  return 0;
}