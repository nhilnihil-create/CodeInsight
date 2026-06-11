#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define repi(i,a,b) for(ll i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define repdi(i,a,b) for(ll i=(a)-1;i>=(b);--i)
#define repd(i,a) repdi(i,a,0)
#define itr(it,a) for( auto it = (a).begin(); it != (a).end(); ++it )
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

using ll = long long;
using P = std::pair<ll, ll>;

constexpr ll INF = 1ll<<60;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template<class S, class T>
std::ostream& operator<< ( std::ostream& out, const std::pair<S,T>& a )
{ std::cout << '(' << a.first << ", " << a.second << ')'; return out; }

template<class T>
std::ostream &operator<< ( std::ostream& out, const std::vector<T>& a )
{ std::cout << '['; rep( i, a.size() ){ std::cout << a[i]; if( i != a.size()-1 ) std::cout << ", "; } std::cout << ']'; return out; }

template <typename T>
struct SegmentTree{
  using F = std::function<T(T,T)>;
  int n;
  F f;
  T ti;
  std::vector<T> dat;

  SegmentTree(){}
  SegmentTree(F f,T ti):f(f),ti(ti){}

  void init(int n_){
    n=1;
    while(n<n_) n<<=1;
    dat.assign(n<<1,ti);
  }

  void build(const std::vector<T> &v){
    int n_=v.size();
    init(n_);
    for(int i=0;i<n_;i++) dat[n+i]=v[i];
    for(int i=n-1;i;i--)
      dat[i]=f(dat[(i<<1)|0],dat[(i<<1)|1]);
  }

  void set_val(int k,T x){
    dat[k+=n]=x;
    while(k>>=1)
      dat[k]=f(dat[(k<<1)|0],dat[(k<<1)|1]);
  }

  T query(int a,int b){
    if(a>=b) return ti;
    T vl=ti,vr=ti;
    for(int l=a+n,r=b+n;l<r;l>>=1,r>>=1) {
      if(l&1) vl=f(vl,dat[l++]);
      if(r&1) vr=f(dat[--r],vr);
    }
    return f(vl,vr);
  }

  template<typename C>
  int find(int st,C &check,T &acc,int k,int l,int r){
    if(l+1==r){
      acc=f(acc,dat[k]);
      return check(acc)?k-n:-1;
    }
    int m=(l+r)>>1;
    if(m<=st) return find(st,check,acc,(k<<1)|1,m,r);
    if(st<=l&&!check(f(acc,dat[k]))){
      acc=f(acc,dat[k]);
      return -1;
    }
    int vl=find(st,check,acc,(k<<1)|0,l,m);
    if(~vl) return vl;
    return find(st,check,acc,(k<<1)|1,m,r);
  }

  template<typename C>
  int find(int st,C &check){
    T acc=ti;
    return find(st,check,acc,1,0,n);
  }
};

ll N;
ll Pr[100010];
P L[100010], R[100010];
ll ans;

int main()
{
  std::cin >> N;

  rep( i, N )
    std::cin >> Pr[i], --Pr[i];

  SegmentTree<P> seg( [&]( const P &p1, const P &p2 ) {
    std::vector<ll> vs = { p1.first, p1.second, p2.first, p2.second };

    std::sort( rall(vs) );

    return P( vs[0], vs[1] );
  }, P( -INF, -INF ) );

  SegmentTree<P> seg2( [&]( const P &p1, const P &p2 ) {
    std::vector<ll> vs = { p1.first, p1.second, p2.first, p2.second };

    std::sort( all(vs) );

    return P( vs[0], vs[1] );
  }, P( INF, INF ) );

  seg.init( N+10 );

  rep( i, N )
  {
    L[i] = seg.query( Pr[i]+1, N );

    seg.set_val( Pr[i], P( i, -INF ) );
  }

  seg2.init( N+10 );

  repd( i, N )
  {
    R[i] = seg2.query( Pr[i]+1, N );

    seg2.set_val( Pr[i], P( i, INF ) );
  }

  rep( i, N )
  {
    if( L[i].first != -INF )
    {
      ll rb = llabs((R[i].first==INF ? N : R[i].first)-i);
      ll lb = llabs((L[i].second==-INF ? -1 : L[i].second)-L[i].first);

      ans += lb*rb*(Pr[i]+1);
    }

    if( R[i].first != INF )
    {
      ll rb = llabs((L[i].first==-INF ? -1 : L[i].first)-i);
      ll lb = llabs((R[i].second==INF ? N : R[i].second)-R[i].first);

      ans += lb*rb*(Pr[i]+1);
    }
  }

  std::cout << ans << std::endl;

  return 0;
}