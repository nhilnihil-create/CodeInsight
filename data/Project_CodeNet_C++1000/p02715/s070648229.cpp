/*    特徴    */
// GCDがi ⇔ 全てiの倍数 ⇔ 全ての要素が≡0(mod i)
// 計算量の見積もりが難しい

/*    教訓    */
// 値を返すべき関数からは値を返すこと
// 制約の下限くらいは最低限テストすること（K=1がコーナーケース）
// a<b のとき、(a-b)%c は負の数を返します

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

//MODINT
//変数名.nでint型の数値を受け取る
struct mint {
  int n;
  mint(int n_ = 0) : n(n_) {}
};

mint operator+(mint a, mint b) { a.n += b.n; if (a.n >= MOD) a.n -= MOD; return a; }
mint operator-(mint a, mint b) { a.n -= b.n; if (a.n < 0) a.n += MOD; return a; }
mint operator*(mint a, mint b) { return (long long)a.n * b.n % MOD; }
mint &operator+=(mint &a, mint b) { return a = a + b; }
mint &operator-=(mint &a, mint b) { return a = a - b; }
mint &operator*=(mint &a, mint b) { return a = a * b; }

int ii() { int x; scanf("%d", &x); return x; }
long long il() { long long x; scanf("%lld", &x); return x; }
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
//GCC9.2.1に変わって動かなくなったので一旦消した そのうち原因を調べる
//auto op = [&](auto p) -> void{ cout << p; };
//auto ov = [&](auto vec) -> void{ cout << vec; };
#define o_map(v){cerr << #v << endl; for(const auto& xxx: v){cout << xxx.first << " " << xxx.second << "\n";}} //動作未確認
void br() { putchar('\n'); }

#define gcd __gcd //llは受け取ってくれない
int lcm(int a, int b){return a / gcd(a, b) * b;}
#define ALL(a) a.begin(),a.end() //sort(ALL(vec));
#define REP(i,m,n) for(ll i=(ll)(m) ; i < (ll) (n) ; i++ )
#define rep(i,n) REP(i,0,n)
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define PB push_back
#define SZ(x) ((int)(x).size) //size()がunsignedなのでエラー避けに

//4近傍（上下左右） rep(i, 2) にすると右・下だけに進む
vector<int> dx_4 = {1, 0, -1, 0};
vector<int> dy_4 = {0, 1, 0, -1};

// coutによるpairの出力（空白区切り）
template<typename T1, typename T2> ostream& operator<<(ostream& s, const pair<T1, T2>& p) {return s << "(" << p.first << " " << p.second << ")";}
// 空白区切りだけ --> return s << "(" << p.first << " " << p.second << ")";
// 見やすくしたいとき --> return s << "(" << p.first << " " << p.second << ")";
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

//最大値、最小値を更新する。aよりbのが大きい（小さい）か等しければaを更新してtrueを返す。そうでなければ何もせずfalseを返す chmax(nowmax,x);
template<typename T>
bool chmax(T& a, T b){return (a = max(a, b)) == b;}
template<typename T>
bool chmin(T& a, T b){return (a = min(a, b)) == b;}

// -------- template end - //


// - library ------------- //

//累乗、階乗、組み合わせの数を返す。MOD版。
//MODはテンプレートで定義したものを使うが、問題の設定と等しいか注意する。
ll modpow(ll x, ll n){return n < 2 ? x : modpow((x * x) % MOD, n / 2) * (n % 2 ? x : 1) % MOD;}
ll modfact(ll n){return n < 2 ? 1 : modfact(n - 1) * n % MOD;}
ll modcomb(ll n, ll r){return modfact(n) * modpow(modfact(r), MOD - 2) % MOD * modpow(modfact(n - r), MOD - 2) % MOD;}

// fN(k) : 1~kな数のみからなる gcd=1 となる数列の数 を求める
ll calculate_fnk(ll k, vector<ll> &fn, vector<ll> &kp){
  if (fn[k] != 0) return fn[k];
  else{
    ll ret = kp[k];
    REP(i, 2, k+1){
      ret = ( ret - calculate_fnk(k / i, fn, kp) ) % MOD;
      ret = ( ret < 0 ? ret+MOD : ret);
    }
    fn[k] = ret;
    return ret;
  }
}


// --------- library end - //


// - main() -------------- //

int main(){

  ll N, K;
  cin >> N >> K;

  // K=1の場合
  if (K==1) ol(1), exit(0);

  // k^N (k:1~floor(K/2)) (mod MOD) を前計算する
  // 考察から、kはfloor(K/2)までで足りるが、K^Nだけは他の部分の計算が全部終わって、最後に fN(K) を求める時に必要となるので、別途求めておく
  vector<ll> kpowered(K/2+1, 0);
  REP(i, 1, K/2+1){
    kpowered[i] = modpow(i, N);
  }
  ll k_tpo_n = modpow(K, N); //K^N

  // i=1~K における fN(floor(K/i)) を全て求め、それぞれ *i して足せば答えになる
  // 厄介なのは i=1 つまり fN(K/1) = fN(K) を求めること

  // DPテーブルを普通に全てなめていっても答えは出るが、TLEする
  // そこで再帰的に fN() を求めていくが、求まるごとに ans += 数 * i をしていく
  // そうすると、最後は自然と答えが計算されている
  
  // i=K のとき、つまりfN(floor(K/K)) = fN(1) = 1（1だけから作る数列の数なので）
  // ちなみに i=K なので、これは gcd=K となる数列の数
  vector<ll> fn(K/2+1, 0); // fn[i]にfN(i:1~K/2)をメモ
  fn[1] = 1;

  // 一番厄介な i=1 のときの fN(K/1) = fN(K)を求めるためには、Σ(i=2~k) fN(floor(K/i))が必要となる
  // fN(floor(K/i)) は、再帰関数 calculate_fnk() を使って求める
  // 求め方としては、fN(k) = k^N - {Σ2~k fN(floor(k/i))} を使う
  // 再帰関数が回る過程で、i=1~K fN(floor(K/i))が求められる
  ll fnK = k_tpo_n; // fN(K)
  REP(i, 2, K+1){
    fnK = (fnK - calculate_fnk(K / i, fn, kpowered)) % MOD;
    fnK = ( fnK < 0 ? fnK+MOD : fnK);
  }



  // 最後に、答えを求める
  // 「要素が 1~K で gcd が i である列の数」は、「要素が 1~floor(K/i) で gcd が 1 である列の数」＝fN(floor(K/i)) であることを使う
  // 上と同じようにcalculate_fnk()を呼び出しているが、今度は全て計算が済んでいるので、ただメモした値を返してくるだけ

  // i = 2 ~ K について求める（gcdが2～Kの場合）
  ll ans = 0;
  REP(i, 2, K+1){
    ans = (ans + (calculate_fnk(K / i, fn, kpowered) * i ) % MOD) % MOD;
    ans = ( ans < 0 ? ans+MOD : ans);
  }

  // i = 1 について求める（gcdが1の場合）
  // fN(K)はgcdがfloor(K/K)すなわちgcd=1となる場合だから、ans += fnK*1
  ans = (ans + fnK) % MOD;

  ol(ans);

// ---------- main() end - //
}