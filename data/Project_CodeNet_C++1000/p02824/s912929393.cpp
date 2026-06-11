#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i=0;i<(n);++i)
using ll = int_fast64_t;
using pll = pair<ll,ll>;
constexpr ll INF = 1LL<<60;
constexpr ll MOD = 1e9+7;
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}return 0;}
#if loc||local
void dump(){cerr<<endl;}
template<class T,class... Ts> void dump(T&& h, Ts&&... t){cerr<<h<<", ";dump(forward<Ts>(t)...);}
#else
void dump(){}
template<class T,class... Ts> void dump(T&& h, Ts&&... t){}
#endif
template<class T> istream &operator>>(istream&is,vector<T>&v){for(auto &elemnt:v)is>>elemnt;return is;}
template<class T,class U> istream &operator>>(istream&is,pair<T,U>&p){is>>p.first>>p.second;return is;}
template<class T> ostream &operator<<(ostream& os,vector<T>const& v){for(auto const& vi:v)os<<vi<<" ";return os;}
template<class T,class U> ostream &operator<<(ostream& os,pair<T,U>const& p){os<<p.first<<","<<p.second;return os;}
template<class T>vector<T> vec(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto vec(size_t a, Ts... ts){return vector<decltype(vec<T>(ts...))>(a, vec<T>(ts...));}

signed main(){

  ll n,m,v,p;
  cin>>n>>m>>v>>p;
  vector<ll> a(n);
  cin>>a;

  sort(rbegin(a),rend(a));

  auto check = [&](ll idx)->ll{
    auto b = a;
    ll key = a[idx]+m;
    rep(i,n){
      if(b[i]<=key)b[i]=min(b[i]+m,key);
      else if(b[i]>key)b[i]+=m;
    }
    vector<ll>d(n);
    rep(i,n)if(b[i]-a[i]<m)d[i]=m-(b[i]-a[i]);
    sort(rbegin(d),rend(d));
    ll cnt = 0;
    rep(i,n)cnt+=b[i]-a[i];
    sort(rbegin(b),rend(b));
    auto itr = lower_bound(b.begin(),b.end(),key,greater<>());
    int id = itr-begin(b);
    for(int i=0;i+id+1<p;++i){
      cnt += d[i];
    }
    return id+1<=p && cnt>=m*v;
  };

  ll loweq = 0;
  ll high = n;
  while(high-loweq>1){
    ll mid = high+loweq>>1;
    if(check(mid))loweq=mid;
    else high=mid;
  }

  cout<<(high)<<endl;

}