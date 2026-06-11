#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define IFOR(i,a,b) for(int i=(b-1);i>=(a);--i)
#define RPT(i,a,b) for(int i=(a);i<((a)+(b));++i)
#define IRPT(i,a,b) for(int i=((a)+(b)-1);i>=(a);--i)
#define ALL(x) x.begin(),x.end()
namespace mymylib {
  using i1 = bool;
  using i8 = char;
  using i16 = short;
  using i32 = int;
  using i64 = long long int;
  using ui8 = unsigned char;
  using ui16 = unsigned short;
  using ui32 = unsigned int;
  using ui64 = unsigned long long int;
  using si8 = signed char;
  using si16 = signed short;
  using si32 = signed int;
  using si64 = signed long long int;
  using d32 = float;
  using d64 = double;
  using d128 = long double;
  namespace constnumber{//ver 1.1
    constexpr mymylib::i32  INF_i32 = ((mymylib::i32)1)<<29;
    constexpr mymylib::i64  INF_i64 = ((mymylib::i64)1)<<60;
    constexpr mymylib::d64  PI_d64 = 3.14159265358979323846264338327950288;
    constexpr mymylib::d128 PI_d128 = 3.14159265358979323846264338327950288;
    constexpr mymylib::d64  LN2_d64 = 0.693147180559945309417232121458;
    constexpr mymylib::d128 LN2_d128 = 0.693147180559945309417232121458;
    constexpr mymylib::d64  LN10_d64  = 2.302585092994045684017991454684;
    constexpr mymylib::d128 LN10_d128 = 2.302585092994045684017991454684;
    constexpr mymylib::d64  GOLDRATIO_d64  = 1.61803398874989484820458683436563811;
    constexpr mymylib::d128 GOLDRATIO_d128 = 1.61803398874989484820458683436563811;
    constexpr mymylib::d64  SILVERRATIO_d64  = 2.414213562373095048801688724210;
    constexpr mymylib::d128 SILVERRATIO_d128 = 2.414213562373095048801688724210;
    constexpr mymylib::d64  E_d64  = 2.71828182845904523536028747135266249;
    constexpr mymylib::d128 E_d128 = 2.71828182845904523536028747135266249;
    constexpr mymylib::d64  OMEGA_d64  = 0.5671432904097838729999686622;
    constexpr mymylib::d128 OMEGA_d128 = 0.5671432904097838729999686622;
  }
  namespace stdplus{//ver 1.6
    namespace iosplus{
      inline void iosFast(){
        std::cin.tie(0);
        std::ios::sync_with_stdio(false);
      }
      inline void iosDouble(mymylib::i32 N){
        std::cout << std::fixed << std::setprecision(N);
      }
      template<typename T> std::istream &operator>>(std::istream &is, std::vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
      template<typename T1, typename T2> std::istream &operator>>(std::istream &is, std::pair<T1,T2> &p){is >> p.first >> p.second; return is; }
      template<typename T> std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec){ os << "["; for (auto v : vec) os << v << ","; os << "]"; return os; }
      template<typename T> std::ostream &operator<<(std::ostream &os, const std::deque<T> &vec){ os << "deque["; for (auto v : vec) os << v << ","; os << "]"; return os; }
      template<typename T> std::ostream &operator<<(std::ostream &os, const std::set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
      template<typename T> std::ostream &operator<<(std::ostream &os, const std::unordered_set<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
      template<typename T> std::ostream &operator<<(std::ostream &os, const std::multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
      template<typename T> std::ostream &operator<<(std::ostream &os, const std::unordered_multiset<T> &vec){ os << "{"; for (auto v : vec) os << v << ","; os << "}"; return os; }
      template<typename T1, typename T2> std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &pa){ os << "(" << pa.first << "," << pa.second << ")"; return os; }
      template<typename TK, typename TV> std::ostream &operator<<(std::ostream &os, const std::map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
      template<typename TK, typename TV> std::ostream &operator<<(std::ostream &os, const std::unordered_map<TK, TV> &mp){ os << "{"; for (auto v : mp) os << v.first << "=>" << v.second << ","; os << "}"; return os; }
    }
    namespace math{
      template<typename T> bool chmax(T &m, const T q) { if (m < q) {m = q; return true;} else return false; }
      template<typename T> bool chmin(T &m, const T q) { if (q < m) {m = q; return true;} else return false; }
      template<typename T1, typename T2> std::pair<T1, T2> operator+(const std::pair<T1, T2> &l, const std::pair<T1, T2> &r) { return std::make_pair(l.first + r.first, l.second + r.second); }
      template<typename T1, typename T2> std::pair<T1, T2> operator-(const std::pair<T1, T2> &l, const std::pair<T1, T2> &r) { return std::make_pair(l.first - r.first, l.second - r.second); }
      inline i64 Bit_i64(i64 x,i32 a){return (((x)>>(a))&((i64)1));}
      inline i32 Bit_i32(i32 x,i32 a){return (((x)>>(a))&((i64)1));}
    }
    namespace random{
      struct random;
    }
    namespace time{
      struct time;
    }
    namespace others{
      template<typename T> void ndarray(std::vector<T> &vec, int len) { vec.resize(len); }
      template<typename T, typename... Args> void ndarray(std::vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }
    }
  }
  namespace strlib{
    template<typename T> bool kaibun(T s);//v1.0 20.03.23
  }
  namespace math{
    using complex_d64 = std::complex<mymylib::d64>;
    using complex_d128 = std::complex<mymylib::d128>;
    template<mymylib::i32 mod> struct modint;//ver 1.0
    namespace bigint{
      struct bigint;
    }
    namespace FFT{
      std::vector<mymylib::math::complex_d64> FFT_i(std::vector<mymylib::math::complex_d64> a);
      std::vector<mymylib::math::complex_d128> FFT_i(std::vector<mymylib::math::complex_d128> a);
    }
    namespace graph{
      void bfs_i(std::vector<std::vector<mymylib::i32>> &G, std::vector<mymylib::i32> &pred, std::vector<mymylib::i32> &dist, std::vector<mymylib::i32> &checked ,mymylib::i32 s, mymylib::i32 n);//ver 1.1
      mymylib::i32 dfs_size(std::vector<vector<mymylib::i32>> &g, std::vector<mymylib::i32> &par, std::vector<mymylib::i32> &siz, mymylib::i32 n, mymylib::i32 pre);//ver 1.0
    }
  }
}

struct mymylib::stdplus::random::random{
  std::random_device rdmdevice;
  std::mt19937_64 mt;
  mymylib::i32 option;
  random(){
    mt = std::mt19937_64(std::chrono::steady_clock::now().time_since_epoch().count());
  }
  random (mymylib::i32 x){
    mt = std::mt19937_64(std::chrono::steady_clock::now().time_since_epoch().count());
    if(x==1) mt = std::mt19937_64(rdmdevice());
  }
  mymylib::i32 uni_i32(mymylib::i32 x, mymylib::i32 y){
    std::uniform_int_distribution<mymylib::i32> urd(x, y);
    return urd(mt);
  }
  mymylib::i64 uni_i64(mymylib::i64 x, mymylib::i64 y){
    std::uniform_int_distribution<mymylib::i64> urd(x, y);
    return urd(mt);
  }
  mymylib::d64 uni_d64(mymylib::d64 x, mymylib::d64 y){
    std::uniform_real_distribution<mymylib::d64> urd(x, y);
    return urd(mt);
  }
};

struct mymylib::stdplus::time::time{
  std::vector<std::chrono::system_clock::time_point> tp;
  time(){
    tp = std::vector<std::chrono::system_clock::time_point>(10);
  }
  time(mymylib::i32 n) {
    tp = std::vector<std::chrono::system_clock::time_point>(n);
  }
  void recordtime(mymylib::i32 x){
    tp[x] = std::chrono::system_clock::now();
  }
  mymylib::i32 caltime(mymylib::i32 x, mymylib::i32 y, mymylib::i32 option = 0){
    return std::chrono::duration_cast<std::chrono::milliseconds>(tp[y] - tp[x]).count();
  }
};



template<class T> using V = vector<T>;
template<class T> using V2 = V<V<T>>;

struct Edge {
  mymylib::i32 to;
  mymylib::i64 c;
  Edge () {}
  Edge (mymylib::i32 a, mymylib::i64 b) {
    to = a;
    c = b;
  }
};

struct UF {
  int n;
  vector< int > par;
  UF(int n) : n(n), par(n, -1) {}
  int find(int x) { return par[x] < 0 ? x : par[x] = find(par[x]); }
  int size(int x) { return -par[find(x)]; }
  bool same(int a, int b) { return find(a) == find(b); }
  void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(par[a] < par[b]) swap(a, b);
    par[b] += par[a];
    par[a] = b;
  }
  void clear() { par.assign(n, -1); }
};

void solve(){
  using namespace mymylib;
  using namespace stdplus::iosplus;
  iosFast();
  int n; cin >> n;
  V<int> a(n); cin >> a;
  V<int> b(n); //map<int,int> c;
  FOR(i,0,n) b[a[i]-1]++;
  sort(ALL(b));
  V<int> s(n+1,0);
  FOR(i,0,n) s[i+1] = s[i] + b[i];
  auto cal_ = [&](int k, int x){
    int d = b.end() - lower_bound(ALL(b), x);
    ll ret = x * d;
    ret += s[n-d];
    ret /= k;
    return ret;
  };
  auto cal = [&](int k){
    int l = 0, r = n/k + 1, m;
    while(r-l>1){
      m = (l+r)>>1;
      bool flg = ( cal_(k,m) >= m);
      if(flg) l = m;
      else r = m;
    }
    return l;
  };
  FOR(i,1,n+1){
    cout << cal(i) << '\n';
  }
}

int main(){
  solve();
  return 0;
}