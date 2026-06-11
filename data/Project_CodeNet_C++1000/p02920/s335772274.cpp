#include <bits/stdc++.h>
using namespace std; void solve(); int main(){cin.tie(0); ios::sync_with_stdio(false); cout<<fixed<<setprecision(10); solve();}
using ll=int_fast64_t; using ld=long double; using pll=pair<ll,ll>; using pld=pair<ld,ld>;
#define fi first
#define se second
#define SELECTOR(_1,_2,_3,SELECT,...) SELECT
#define rep(...) SELECTOR(__VA_ARGS__,_rep1,_rep0)(__VA_ARGS__)
#define _rep0(i,n) for(ll i=0;i<n;++i)
#define _rep1(i,k,n) for(ll i=k;i<n;++i)
template<class T> void vecout(const T &v){for(auto it=v.begin();it!=v.end();++it,cout<<(it!=v.end()?" ":"\n"))cout<<*it;}

void solve(){
  ll n; cin>>n;
  ll N=1<<n;
  ll INF=1001001001;
  vector<ll> s(N);
  rep(i,N) cin>>s[i];
  sort(s.rbegin(),s.rend());
  vector<ll> p,q;
  // initialize
  p.push_back(s[0]);
  s[0]=INF;
  rep(i,n){
    sort(p.rbegin(),p.rend());
    q=p;
    auto it=s.begin();
    for(auto itq=q.begin();itq!=q.end();++itq){
      while(it!=s.end()){
        if(*itq<=*it){
          ++it;
        } else {
          p.push_back(*it);
          *it=INF;
          ++it;
          break;
        }
      }
    }
  }
  cout<<(p.size()==N?"Yes":"No")<<"\n";
}