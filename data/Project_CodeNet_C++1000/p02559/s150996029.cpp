//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using db = double;
using ld = long double;
template<typename T> using V = vector<T>;
template<typename T> using VV = vector<vector<T>>;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define siz(v) (ll)(v).size()
#define rep(i,a,n) for(ll i=a;i<(ll)(n);++i)
#define repr(i,a,n) for(ll i=n-1;(ll)a<=i;--i)
#define ENDL '\n'
typedef pair<int,int> Pi;
typedef pair<ll,ll> PL;
constexpr ll mod = 1000000007; // 998244353;
constexpr ll INF = 1000000099;
constexpr ll LINF = (ll)(1e18 +99);
const ld PI = acos((ld)-1);
const vector<ll> dx={-1,1,0,0},dy={0,0,-1,1};
template<typename T,typename U> inline bool chmin(T& t, const U& u){if(t>u){t=u;return 1;}return 0;}
template<typename T,typename U> inline bool chmax(T& t, const U& u){if(t<u){t=u;return 1;}return 0;}
template<typename T> inline T gcd(T a,T b){return b?gcd(b,a%b):a;}

template<typename T,typename Y> inline T mpow(T a, Y n) {
  T res = 1;
  for(;n;n>>=1) {
    if (n & 1) res = res * a;
    a = a * a;
  }
  return res;
}

template <typename T> V<T> prefix_sum(const V<T>& v) {
  int n = v.size();
  V<T> ret(n + 1);
  rep(i, 0, n) ret[i + 1] = ret[i] + v[i];
  return ret;
}

template<typename T,typename Y>
ostream& operator<<(ostream& os,const pair<T,Y>& p){
  return os<<"{"<<p.fs<<","<<p.sc<<"}";
}
template<typename T> ostream& operator<<(ostream& os,const V<T>& v){
  os<<"{";
  for(auto e:v)os<<e<<",";
  return os<<"}";
}
template<typename ...Args>
void debug(Args&... args){
  for(auto const& x:{args...}){
    cerr<<x<<' ';
  }
  cerr<<ENDL;
}
template <typename T> struct BIT {
  int n;
  vector<T> bit;  // 1-indexed

  BIT() : n(-1) {}

  BIT(int n_, T d) : n(n_), bit(n_ + 1, d) {}
  // initialization2 n_要素数 d初期値

  T sum(int i) {
    T s = bit[0];
    for(int x = i; x > 0; x -= (x & -x)) s += bit[x];
    return s;
  }
  // 1からiまでの和(1-indexed)

  void add(int i, T a) {
    if(i == 0) return;
    for(int x = i; x <= n; x += (x & -x)) bit[x] += a;
  }
  // iにa加える

  T lower_bound(T w) {
    if(w <= 0) return 0;
    T x = 0, r = 1;  // xは横の位置を管理するイメージ
    while(r < n) r <<= 1;
    for(T k = r; k > 0; k >>= 1) {  //上の層から見る
      if(x + k <= n && bit[x + k] < w) {
        w -= bit[x + k];
        x += k;  //右の要素に移る
      }
    }
    return x + 1;
  }
  // indまでの区間和がw以上になるような最小のindを求める

  T sum0(int i) { return sum(i + 1); }
  void add0(int i, T a) { add(i + 1, a); }  // 0-index用

  T query(int l, int r) { return sum(r - 1) - sum(l - 1); }  //[l,r)の和を求める

  T query0(int l, int r) { return sum(r) - sum(l); }  // 0-index用
};

/*Binary Index Tree
区間和の取得と一点の更新が対数時間でできる
1-indexedに0を投げると何もしない*/

template <typename T>
void kukanadd(BIT<T>& p, BIT<T>& q, T w, T a, T b) {  //[a,b)にwを加算
  p.add0(a, -w * a);
  p.add0(b, w * b);
  q.add0(a, w);
  q.add0(b, -w);
}

template <typename T>
T kukansum(BIT<T>& p, BIT<T>& q, T b) {  //[0,b)の区間和を求める
  return p.sum0(b) + q.sum0(b) * b;
}

signed main(){
  cin.tie(0);cerr.tie(0);ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(20);
  ll n,q;cin>>n>>q;
  BIT<ll> b(n,0);
  rep(i,0,n){
    ll x;cin>>x;
    b.add0(i,x);
  }
  rep(i,0,q){
    ll t,p,x;cin>>t>>p>>x;
    if(t==0)b.add0(p,x);
    else cout<<b.query0(p,x)<<ENDL;
  }
}
//! ( . _ . ) ! 
//CHECK overflow,vector_size,what to output?