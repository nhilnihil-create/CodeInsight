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
  multiset<ll> S{-1};
  rep(_,1<<n){
    ll s; cin>>s;
    S.insert(s);
  }

  vector<ll> now{*S.rbegin()}; // 初めは最大値から
  rep(_,n){
    auto next=now;
    foreach(v,now){
      auto it=S.lower_bound(v);
      ll s=*(--it);
      if(s==-1){
        cout<<"No"<<"\n";
        return;
      }
      S.erase(it);
      next.push_back(s);
    }
    now=next;
  }
  cout<<"Yes"<<"\n";
}
