#include <cstdio>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,a) repi(i,0,a)
#define all(a) (a).begin(), (a).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using ll = long long;
using namespace std;

template <typename T>
struct SegmentTree{
  using F = function<T(T,T)>;
  int n;
  F f;
  T ti;
  vector<T> dat;

  SegmentTree(){}
  SegmentTree(F f,T ti):f(f),ti(ti){}

  void init(int n_){
    n=1;
    while(n<n_) n<<=1;
    dat.assign(n<<1,ti);
  }

  void build(const vector<T> &v){
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

constexpr ll INF = 1ll<<60;

ll N, M;
std::string S;
ll dp[100010];
std::vector<ll> ans;
std::vector<ll> preV, pre;

int main()
{
  std::cin >> N >> M >> S;

  SegmentTree<ll> seg( []( ll a, ll b ){ return std::min(a,b); }, INF );

  seg.init( N+1 );

  rep( i, N+1 )
    dp[i] = INF;

  dp[N] = 0;
  seg.set_val( N, dp[N] );

  for( int i = N-1; i >= 0; --i )
  {
    if( S[i] == '0' )
    {
      ll mi = seg.query( i+1, std::min<ll>(i+1+M,N+1) );

      //printf( "(%d) %lld\n", i, mi );

      if( mi != INF )
        dp[i] = mi+1;

      seg.set_val( i, dp[i] );
    }
  }

  //rep( i, N+1 )
    //printf( "dp[%d] = %lld\n", i, dp[i] );

  if( dp[0] == INF )
  {
    puts("-1");

    return 0;
  }

  int p = 0;

  while( p < N )
  {
    int prv = p;

    while( dp[prv]-1 != dp[p] && p <= N )
      ++p;

    printf( "%d%c", p-prv, p==N?'\n':' ' );
  }
  
  return 0;
}