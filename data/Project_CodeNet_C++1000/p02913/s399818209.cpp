#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld  = long double;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
const int INF=1e9+7;
const ll LINF=9223372036854775807;
const ll MOD=1e9+7;
const ld PI=acos(-1);
const ld EPS = 1e-10; //微調整用（EPSより小さいと0と判定など）

int ii() { int x; if (scanf("%d", &x)==1) return x; else return 0; }
long long il() { long long x; if (scanf("%lld", &x)==1) return x; else return 0; }
string is() { string x; cin >> x; return x; }
char ic() { char x; cin >> x; return x; }
void oi(int x) { printf("%d ", x); }
void ol(long long x) { printf("%lld ", x); }
void od_nosp(double x) { printf("%.15f", x); } // 古い問題用
void od(double x) { printf("%.15f ", x); }
// long doubleで受け取り、fをLfなどに変えて出力すると、変な数値が出る
// それをなんとかするには独自の出力を作らなければならなそう
void os(const string &s) { printf("%s ", s.c_str()); }
void oc(const char &c) { printf("%c ", c); }
#define o_map(v){cerr << #v << endl; for(const auto& xxx: v){cout << xxx.first << " " << xxx.second << "\n";}} //動作未確認
void br() { putchar('\n'); }

// #define gcd __gcd //llは受け取らない C++17~のgcdと違うので注意
// int lcm(int a, int b){return a / gcd(a, b) * b;}
#define begin_end(a) a.begin(),a.end() //sort(begin_end(vec));
#define REP(i,m,n) for(ll i=(ll)(m) ; i < (ll)(n) ; i++ )
#define DREP(i,m,n) for(ll i=(ll)(m) ; i > (ll)(n) ; i-- )
#define rep(i,n) REP(i,0,n)
#define m_p(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define p_b push_back
#define SZ(x) ((ll)(x).size()) //size()がunsignedなのでエラー避けに
#define endk '\n'


// coutによるpairの出力（空白区切り）
template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& p) {return s << "(" << p.first << " " << p.second << ")";}
// coutによるvectorの出力（空白区切り）
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i]; if (i < len - 1) s << " "; //"\t"に変えるとTabで見やすく区切る
  }
  return s;
}
// coutによる多次元vectorの出力（空白区切り）
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) {
    s << vv[i] << endl;
  }
  return s;
}

//最大値、最小値の更新。更新したor等しければtrueを返す
template<typename T>
bool chmax(T& a, T b){return (a = max(a, b)) == b;}
template<typename T>
bool chmin(T& a, T b){return (a = min(a, b)) == b;}

//4近傍（上下左右） rep(i, 2) にすると右・下だけに進む
vector<int> dx_4 = {1, 0, -1, 0};
vector<int> dy_4 = {0, 1, 0, -1};

// -------- template end - //


// - library ------------- //

// RollingHash rh(文字列); で生成 ※第二引数でbaseを指定しなければ、乱数で生成
//  ※ 一致判定をする時は、2個目以降の RH を生成する際の第二引数で rh.base を指定
// rh.get(l, r) := [l, r) のハッシュ値

// LCP（最長共通接尾辞）の長さをO(logN)で求められる
// rh.lcp(l1, r1, l2, r2) := LCP of s[l1:r1) and s[l1:r1)
// rh1.lcp(rh2, l1, r1, l2, r2) := LCP of s1[l1:r1) and s2[l2:r2)
struct RollingHash {
  using ui64 = uint64_t;
  using ui128 = __uint128_t;
  static const ui64 mod = (1ull<<61) - 1;
  vector<ui64> hash, power;
  ui64 base;
 
  static inline ui64 add(ui64 a, ui64 b) { if ((a += b) >= mod) a -= mod; return a; }
  static inline ui64 mul(ui64 a, ui64 b) { ui128 c = ui128(a)*b; return add(c>>61, c&mod); }
  static inline ui64 generate_base() {
    mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<ui64> rand(2, mod-2);
    return rand(mt);
  }
 
  template<typename T>
  RollingHash(const T &s, ui64 b=0) : base(b) {
    if (base == 0) base = generate_base();
    int n = s.size();
    hash.assign(n+1, 0);
    power.assign(n+1, 1);
    rep(i, n) {
      power[i+1] = mul(power[i], base);
      hash[i+1] = add(mul(hash[i], base), s[i]);
    }
  }
 
  ui64 get(int l, int r) const { return add(hash[r], mod - mul(hash[l], power[r-l])); }
 
// longest common prefix of s[l1:r1) and s[l2:r2)
  int lcp(int l1, int r1, int l2, int r2) const {
    int len = min(r1-l1, r2-l2);
    int ok = 0, ng = len+1;
    while (ng-ok > 1) {
      int md = (ok+ng)>>1;
      if (get(l1, l1+md) == get(l2, l2+md)) ok = md;
      else ng = md;
    }
    return ok;
  }
  
// longest common prefix of s[l1:r1) and t[l2:r2)
  int lcp(RollingHash &rh, int l1, int r1, int l2, int r2) const {
    int len = min(r1-l1, r2-l2);
    int ok = 0, ng = len+1;
    while (ng-ok > 1) {
      int md = (ok+ng)>>1;
      if (get(l1, l1+md) == rh.get(l2, l2+md)) ok = md;
      else ng = md;
    }
    return ok;
  }
};



// --------- library end - //


int main(){

  ll N = il();
  string S = is();

  RollingHash rh(S);

  ll ans = 0;

  // 仕切り1) i : 0 ~ N-2 : 添字 i から使い始める -> [i, j)
  // 仕切り2) j : i+1 ~ N-1 : 添字 j から右側の仕切り -> [j, N)
  // s1[0, i), s2[i, N) に分ける
  rep(i, N-1) REP(j, i+1, N) chmax(ans, ll(rh.lcp(i, j, j, N)));

  cout << ans << endk;

}