#include <bits/stdc++.h>
using namespace std;using ll=int_fast64_t;using ld=long double;using pll=pair<ll,ll>;using pld=pair<ld,ld>;
const ll INF=1LL<<60;void solve();int main(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(10);solve();}
#define SELECTOR(_1,_2,_3,_4,SELECT,...) SELECT
#define rep(...) SELECTOR(__VA_ARGS__,_rep2,_rep1,_rep0)(__VA_ARGS__)
#define _rep0(i,n) for(ll i=0;i<n;++i)
#define _rep1(i,k,n) for(ll i=k;i<n;++i)
#define _rep2(i,k,n,d) for(ll i=k;d!=0&&d>0?i<n:i>n;i+=d)
#define foreach(i,A) for(auto &i:A)
#define all(A) A.begin(),A.end()
#define len(A) (ll)A.size()
template<class T> vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<class... Ts> auto make_v(size_t a,Ts... ts){return vector<decltype(make_v(ts...))>(a,make_v(ts...));}
template<class T> inline bool chmax(T &a,const T &b){if(a<b){a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a,const T &b){if(a>b){a=b; return 1;} return 0;}

void solve(){
  ll n; cin>>n;
  vector<pll> PI(n);
  rep(i,n){
    ll p; cin>>p;
    PI[i]={p,i};
  }
  sort(all(PI),greater<pll>());
  
  ll ans=0;
  multiset<ll> S{-1,-1,n,n};
  foreach(tup,PI){
    ll p,i; tie(p,i)=tup;
    auto it1=S.insert(i);
    auto it2=it1;
    ll l0=*(--it1), l1=*(--it1);
    ll r0=*(++it2), r1=*(++it2);
    ans+=p*((l0-l1)*(r0-i)+(i-l0)*(r1-r0));
  }

  cout<<ans<<"\n";
}