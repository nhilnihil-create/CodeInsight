/*    特徴    */
// GCDがi ⇔ 全てiの倍数
// 約数系包除

/*    教訓    */
// 制約の下限くらいは最低限テストすること（K=1がコーナーケース）
// a<b のとき、(a-b)%c は負の数を返します
// 再帰関数の基本的構成を意識する
// ・再帰関数は2ブロックに分かれる
// （ブロック1）値をただちに求められないので、再度関数を呼ぶ
// （ブロック2）値が求められる(or前計算済)ので、値を返す
// ・ブロック1の最後は、値をメモして返す
// ・ブロック1の再帰関数呼び出しは、ブロック2に向かっていく方向でないとならない

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



// ゼロ除算エラーの対策をしていないので注意
// 関数の引数の評価順序が未規定のため、ceil_divide(ii(), ii())はNG
ll ceil_divide(ll a, ll b) {
  return (a + b - 1) / b;
}

// 累乗、階乗、組み合わせの数を返す。MOD版。
// ちょっと動作が怪しいかもしれない（特にmodfactとmodcomb）
// MODはテンプレートで定義したものを使うが、問題の設定と等しいか注意する。
ll modpow(ll x, ll n){return n < 2 ? x : modpow((x * x) % MOD, n / 2) * (n % 2 ? x : 1) % MOD;} //llpowがあるからいらない？？ 
ll modfact(ll n){return n < 2 ? 1 : modfact(n - 1) * n % MOD;}
ll modcomb(ll n, ll r){return modfact(n) * modpow(modfact(r), MOD - 2) % MOD * modpow(modfact(n - r), MOD - 2) % MOD;}


// 再帰的に各DPの値を求める
ll calculate_fnk(ll N, ll K, ll i, vector<ll> &k_powered, vector<ll> &DP){
  if (DP[i] != 0) return DP[i];
  else{
    ll valid_kjs = 0; // kjとして使える数字の数（k<=Kなiの倍数kiの数）
    ll kj = 1;
    while(kj*i <= K){
      valid_kjs++;
      kj++;
    }
    // return valid_kjs^N - Σ(k=2~floor(K/i))fN(ki)
    // ここで、calculate_fnkの第三引数にkjそのものを使わないこと。
    // kjは常に2~floor(K/i)となるが、それらは求められていないので、iをかけたkj*iを使わないといけない。
    // kj*iを使うことで、「今fN(i)を求めたいiよりも、引数の大きいfN()を求めていく」ことになるので、再帰していく過程で、いつか計算済みのfN(x)=DP[x]にたどり着く。
    ll ret = k_powered[valid_kjs];
    REP(kj2, 2, K/i+1){
      ret = (ret - calculate_fnk(N, K, kj2*i, k_powered, DP)) % MOD;
      ret = ( ret<0 ? ret += MOD : ret );
    }
    DP[i] = ret;
    return ret;
  }

}

// --------- library end - //


// - main() -------------- //

int main(){

  ll N, K;
  cin >> N >> K;

  if (K==1){
    ol(1);
    return(0);
  }

  vector<ll> DP(K+1, 0); // DP[i] : GCDがiとなる数列の数

  vector<ll> k_powered(floor(K/2)+1); // k^Nを前計算。k<=floor(K/2)で足りる
  REP(i, 1, floor(K/2)+1){
    k_powered[i] = modpow(i, N);
  }
  ll K_tpo_N = modpow(K, N); // K^N はfN(1)を求める際に必要になるので別途求める

  // ceil((K+1)/2)~K な i にあっては DP[i] = 1
  REP(i, ceil_divide(K+1, 2), K+1){
    DP[i] = 1;
  }

  // DP[1]=fN(1) を求めようとするが、その過程で再帰的にfN(k)が全て求められる
  DP[1] = K_tpo_N;
  REP(i, 2, K+1){
    DP[1] = (DP[1] - calculate_fnk(N, K, i, k_powered, DP)) %MOD;
    DP[1] = ( DP[1]<0 ? DP[1] += MOD : DP[1] );
  }

  // 答えを出力
  ll ans = 0;
  REP(i, 1, K+1){
    ans = (ans + (DP[i] * i % MOD)) % MOD;
  }

  ol(ans);



// ---------- main() end - //
}