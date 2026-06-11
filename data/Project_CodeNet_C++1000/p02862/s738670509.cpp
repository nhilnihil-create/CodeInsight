/*    特徴    */

/*    教訓    */

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld  = long double;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
const int INF=1e9+7;
const ll LINF=9223372036854775807;
const ll MOD=1e9+7;
const ld PI=acos(-1);
const ld EPS = 1e-9; //微調整用（EPSより小さいと0と判定など）

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

#define gcd __gcd //llは受け取らない C++17~のgcdと違うので注意
int lcm(int a, int b){return a / gcd(a, b) * b;}
#define begin_end(a) a.begin(),a.end() //sort(begin_end(vec));
#define REP(i,m,n) for(ll i=(ll)(m) ; i < (ll) (n) ; i++ )
#define rep(i,n) REP(i,0,n)
#define m_p(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define p_b push_back
#define SZ(x) ((int)(x).size) //size()がunsignedなのでエラー避けに

//4近傍（上下左右） rep(i, 2) にすると右・下だけに進む
vector<int> dx_4 = {1, 0, -1, 0};
vector<int> dy_4 = {0, 1, 0, -1};

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

// -------- template end - //


// - library ------------- //

  // mod. m での a の逆元 a^{-1} を計算する
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

// MOD版
ll comb(ll n, ll k){
  if (n < k) return 0;
  if (k > n / 2) k = n - k;
  ll ret = 1;
  ll divider = 1;
  rep(i, k) ret = ret * (n - i) % MOD;
  rep(i, k) divider = divider * (i + 1) % MOD;
  return ret * modinv(divider, MOD) % MOD;
}

// --------- library end - //


int main(){

  ll x, y;
  cin >> x >> y;

  ll ans = 0;
  if ((x+y)%3!=0) ans = 0;
  else if (abs(x - y) > (x+y)/3) ans = 0;
  else{
    ll rank = (x + y) / 3;
    ll k = abs((x+y) / 3 - y);
    // rank r とすると、答えは rCk となる

    ans = comb(rank, k);

  }

  cout << ans << endl;
  
}