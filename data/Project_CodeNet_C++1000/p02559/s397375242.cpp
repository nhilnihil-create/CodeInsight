// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
// #include <atcoder/all>
using namespace std;
// using namespace atcoder;

#define int long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for (int i = 0; i < n; ++i)
#define REP(i, n) for (int i = 0; i < n; ++i)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x) cout << #x << " = " << (x) << endl;
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back
#define SP << " " <<

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
typedef vector<int> vec;
typedef vector<P> pvec;
typedef vector<vector<int>> vvec;
typedef vector<vector<P>> pvvec;
typedef priority_queue<int> PQI;
typedef priority_queue<P> PQP;
typedef priority_queue<int,vector<int>,greater<int>> PQIG;
typedef priority_queue<P,vector<P>,greater<P>> PQPG;

const vector<int> DX = {0, -1, 0, 1, 1, 1, -1, -1};
const vector<int> DY = {1, 0, -1, 0, 1, -1, 1, -1};
constexpr int MOD = (1000000007);
// const int MOD = (998244353);
// const int INF = (1 << 30); // 1073741824
const ll INF = (1LL << 60); // 1152921504606846976
const double PI = (3.141592653589794);
const double EPS = (0.0000000001); // 10^(-10)

template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template<class T> inline T ceil(T a, T b) {return T((a + b - 1) / b);}
template<class T> inline T round(T a, T b) {return T(a / b);}
template< typename T1, typename T2 > istream &operator>>(istream &is, pair< T1, T2 > &p) { is >> p.first >> p.second; return is; }
template <class T> inline void out(T &a) { bool flag=true; for(auto&x:a){if(flag) {flag=false;} else{ cout << ' '; } cout<<x; } cout << endl; }



//----------------------------------------------------------------
int nmax=200000; // 2*(10^5)
vvec G(nmax);


/* SegTree<X>(n,fx,ex): モノイド(集合X, 二項演算fx, 単位元ex)についてサイズnで構築
    set(int i, X x), build(): i番目の要素をxにセット。まとめてセグ木を構築する。O(n)
    update(i,x): i 番目の要素を x に更新。O(log(n))
    query(a,b): [a,b) 全てにfxを作用させた値を取得。O(log(n))
*/
template <typename X>
struct SegTree
{
  using FX = function<X(X, X)>; // X•X -> X となる関数の型
  int n;
  FX fx;
  const X ex;
  vector<X> dat;
  SegTree() {}
  SegTree(int n_, FX fx_, X ex_) : n(), fx(fx_), ex(ex_), dat(n_ * 4, ex_)
  {
    int x = 1;
    while (n_ > x)
    {
      x *= 2;
    }
    n = x;
  }
  void vecset(vector<X> v)
  {
    for (int i = 0; i < v.size(); i++)
    {
      set(i, v[i]);
    }
    build();
  }
  void set(int i, X x) { dat[i + n - 1] = x; }
  void build()
  {
    for (int k = n - 2; k >= 0; k--)
      dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
  }
  void update(int i, X x)
  {
    i += n - 1;
    dat[i] = x;
    while (i > 0)
    {
      i = (i - 1) / 2; // parent
      dat[i] = fx(dat[i * 2 + 1], dat[i * 2 + 2]);
    }
  }
  X query(int a, int b) { return query_sub(a, b, 0, 0, n); }
  X query_sub(int a, int b, int k, int l, int r)
  {
    if (r <= a || b <= l)
    {
      return ex;
    }
    else if (a <= l && r <= b)
    {
      return dat[k];
    }
    else
    {
      X vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
      X vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
      return fx(vl, vr);
    }
  }
};

// // RMQ
// auto fx = [](int x1, int x2) -> int { return min(x1, x2); };
// int ex = numeric_limits<int>::max();
// SegTree<int> rmq(n, fx, ex);

// // RSQ
// auto fx = [](int x1, int x2) -> int { return (x1 + x2); };
// int ex = 0LL;
// SegTree<int> rsq(n, fx, ex)  ;


void solve4ts()
{
  
  int n;
  int q;
  cin>>n>>q;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  auto fx =[](int x1,int x2) -> int{ return x1+x2;};
  int ex=0;
  SegTree<int> seg(n,fx,ex);
  seg.vecset(a);
  rep(i,q){
    int t,a,b;
    cin>>t>>a>>b;
    if(t==0){
      int memo=seg.query(a,a+1);
      seg.update(a,memo+b);
    }
    else{
      cout<<seg.query(a,b)<<endl;
    }
  }
  
  
}
//-----------------------------------------------------------------

signed main(){ ios::sync_with_stdio(false); cin.tie(0); cout << fixed << setprecision(15);
  int repeat = 1;
  // cin >> repeat;
  while(repeat--) solve4ts();
}

/*

g++ -std=c++1z code.cpp

./a.out

python3 expander.py code.cpp

*/