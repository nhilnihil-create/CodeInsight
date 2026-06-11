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

// 1次元座標圧縮
// 昇順ソート -> 重複削除 -> 元の値が何番目にあるかを二分探索するだけ
vector<ll> compress(vector<ll> &org_vec){
  vector<ll> vals = org_vec;
  vector<ll> res_vec;
  sort(vals.begin(), vals.end());
  // unique は隣接する重複要素を削除するが、vectorのサイズは変わらない（前に詰める）
  // erase(iter1, iter2) でiter1の直後～iter2までを削除する
  // unique は末尾に残ったゴミの手前のポインタを返すので、これでゴミ削除ができる
  vals.erase(unique(vals.begin(), vals.end()), vals.end());

  for (ll i = 0; i < org_vec.size(); ++i){
    res_vec.push_back(lower_bound(vals.begin(), vals.end(), org_vec[i]) - vals.begin());
  }

  return res_vec;
}

/* SegTreeLazy<X,M>(n,fx,fa,fm,ex,em): モノイド(集合X, 二項演算fx,fa,fm, 単位元ex,em)についてサイズnで構築
  set(int i, X x), build(): i番目(0-indexed)の要素をxにset()していき、最後にbuild()でまとめてセグ木を構築。O(n)
  update(a,b,x): [a,b) 全てを x で更新（置き換えるわけではなく、演算faを行う）。O(log(n)) 0-indexed
  query(a,b):  [a,b) 全てにfxを作用させた値を取得。O(log(n)) 0-indexed
*/
template <typename X, typename M>
struct SegTreeLazy {
    using FX = function<X(X, X)>;
    using FA = function<X(X, M)>;
    using FM = function<M(M, M)>;
    int n;
    FX fx;
    FA fa;
    FM fm;
    const X ex;
    const M em;
    vector<X> dat;
    vector<M> lazy;
    SegTreeLazy(int n_, FX fx_, FA fa_, FM fm_, X ex_, M em_)
        : n(), fx(fx_), fa(fa_), fm(fm_), ex(ex_), em(em_), dat(n_ * 4, ex), lazy(n_ * 4, em) {
        int x = 1;
        while (n_ > x) x *= 2;
        n = x;
    }
    void set(int i, X x) { dat[i + n - 1] = x; }
    void build() {
        for (int k = n - 2; k >= 0; k--) dat[k] = fx(dat[2 * k + 1], dat[2 * k + 2]);
    }
    /* lazy eval */
    void eval(int k) {
        if (lazy[k] == em) return;  // 更新するものが無ければ終了
        if (k < n - 1) {            // 葉でなければ子に伝搬
            lazy[k * 2 + 1] = fm(lazy[k * 2 + 1], lazy[k]);
            lazy[k * 2 + 2] = fm(lazy[k * 2 + 2], lazy[k]);
        }
        // 自身を更新
        dat[k] = fa(dat[k], lazy[k]);
        lazy[k] = em;
    }
    void update(int a, int b, M x, int k, int l, int r) {
        eval(k);
        if (a <= l && r <= b) {  // 完全に内側の時
            lazy[k] = fm(lazy[k], x);
            eval(k);
        } else if (a < r && l < b) {                     // 一部区間が被る時
            update(a, b, x, k * 2 + 1, l, (l + r) / 2);  // 左の子
            update(a, b, x, k * 2 + 2, (l + r) / 2, r);  // 右の子
            dat[k] = fx(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }
    void update(int a, int b, M x) { update(a, b, x, 0, 0, n); }
    X query_sub(int a, int b, int k, int l, int r) {
        eval(k);
        if (r <= a || b <= l) {  // 完全に外側の時
            return ex;
        } else if (a <= l && r <= b) {  // 完全に内側の時
            return dat[k];
        } else {  // 一部区間が被る時
            X vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
            X vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
            return fx(vl, vr);
        }
    }
    X query(int a, int b) { return query_sub(a, b, 0, 0, n); }
};

// ゼロ除算エラーの対策をしていないので注意
// 関数の引数の評価順序が未規定のため、ceil_divide(ii(), ii())はNG
ll ceil_divide(ll a, ll b) {
  return (a + b - 1) / b;
}

// --------- library end - //


int main(){

  
  ll N, D, A;
  cin >> N >> D >> A;

  // 座標圧縮して、圧縮後の値を昇順で入れるvector
  vector<ll> vals;
  vector<ll> cpd_vals; // 座標圧縮後
  ll len; // 意味のある座標数
  // 座標圧縮後に作る、値を入れると idx_to_val における添字を返すmap
  map<ll, ll> val_to_idx;

  vector<pll> xhs;
  rep(i, N){
    ll x = il();
    ll h = il();
    vals.p_b(x);   // x+D で爆弾を落とすので、x ~ x+D+D まで爆風が届く
    vals.p_b(x+D);
    vals.p_b(x+D+D);
    xhs.p_b(m_p(x, h));
  }

  // 座標圧縮
  cpd_vals = compress(vals);
  // 値から添字を出すmap
  rep(i, SZ(vals)) val_to_idx[vals[i]] = cpd_vals[i];
  len = SZ(val_to_idx);
  
  // モンスターをXiの昇順でソート
  sort(begin_end(xhs));

  // 爆風（爆発によって減らせるHP）を管理するセグ木
  // 「座標の値」でなく「圧縮後の添字」で入れること

  using X = ll; // 集合Xを定義（答えとなる集合）
  using M = ll; // 集合Mを定義（作用素となる集合）
  // 単位元の処理に気をつけて、3つの演算を定義する
  // 区間更新であれば return ( x2==単位元(ありえない入力) ? x1 : x2 ) など
  // fx : Xをマージする演算。求めたい区間"和"や区間"min"などを素直に入れる
  auto fx = [](X x1, X x2) -> X { return ( x1 + x2 ); };
  // fm : Mをマージする演算。作用素がlazy[]にたまる部分に対応。((gm1)m2)m3=g(m1m2m3)となるように気を付けて演算を定義する
  auto fm = [](M m1, M m2) -> M { return ( m1 + m2 ); };
  // fa : MからXに作用する演算。区間加算や区間更新など、更新クエリを入れる
  auto fa = [](X x, M m) -> X { return ( x + m ); };
  ll ex = 0; // モノイド(X,fx) の単位元
  ll em = 0; // モノイド(M,fm) の単位元  (注) fm(x, em) -> x となる必要あり
  
  // 要素数を指定する
  SegTreeLazy<X, M> segt(len, fx, fa, fm, ex, em);

  rep(i, len) segt.set(i, 0); // 初期値。指定がなければ単位元とする？
  segt.build();

  ll ans = 0;
  rep(i, N){
    // Xi の昇順で、モンスターを貪欲に処理していく
    ll x = xhs[i].first; // 座標
    ll h = xhs[i].second; // 体力

    // 溜まっていた爆風をモンスター（xの位置）に当てて、hp<=0 になれば何もしない
    h = max(0LL, h - segt.query(val_to_idx[x], val_to_idx[x] + 1));
    if (h <= 0) continue;
    else{
      // hpが残っている。爆風を更に吹かせる必要がある
      ans += ceil_divide(h, A);

      // 爆風をどこからどこまでの添字範囲に吹かせるか？
      // 左から見ていっているので、できるだけ右の方で爆破させた方が良い
      // -> x+D で爆破するので、[x, x+D+D] = [x, x+D+D+1) に爆風が届く
      segt.update(val_to_idx[x], val_to_idx[x+D+D]+1, ceil_divide(h, A) * A);
    }
  }

  cout << ans << endk;


}