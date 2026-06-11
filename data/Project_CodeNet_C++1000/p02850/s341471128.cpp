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
#define REP(i,m,n) for(ll i=(ll)(m) ; i < (ll) (n) ; i++ )
#define rep(i,n) REP(i,0,n)
#define m_p(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define p_b push_back
#define SZ(x) ((int)(x).size) //size()がunsignedなのでエラー避けに


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

  
// 辺 隣接リスト表現
vector<vector<ll> > edges_adj;

// 辺の色を入れるmap
// value : <a, b>  key : 色(1~)
map<pll, ll> colors;

// 根付き木上でのDFS
// 来た道を戻らない
// 来た道の色（ng_color）は使えないが、逆にそれ以外は自由に使えるので1から順に振っていく
void dfs(ll from, ll here, ll ng_color){
  if (from == -1){
    // スタートの場合
    ll color = 1;
    for (ll next : edges_adj[0]){
      if (next == from) continue;
      dfs(here, next, color);
      // dfsしたということは、hereとnextを繋ぐ辺をcolorで塗ったということ
      colors[m_p(min(here, next), max(here, next))] = color;
      color++;
    }
  }
  else{
    // それ以外
    ll color = 1;
    for (ll next : edges_adj[here]){
      if (next == from) continue;
      if (color==ng_color) color++;
      dfs(here, next, color);
      // dfsしたということは、hereとnextを繋ぐ辺をcolorで塗ったということ
      colors[m_p(min(here, next), max(here, next))] = color;
      color++;
    }
  }
}


// --------- library end - //


int main(){

  ll N = il();

  // 辺 隣接リスト表現
  edges_adj = vector<vector<ll> >(N, vector<ll>() );
  // 辺 pll
  vector<pll> edges_pll;
  // 何色目まで使ったかのチェックに使う（次数を足していく）
  vector<ll> buckets(N, 0);
  rep(i, N-1){
    ll a = il() - 1;
    ll b = il() - 1;

    // 最後に答えを出力する時のため、a < b に統一しておく
    if (a > b) swap(a, b);
    edges_pll.p_b(m_p(a, b));

    edges_adj[a].p_b(b);
    edges_adj[b].p_b(a);

    buckets[a]++;
    buckets[b]++;
  }

  // 何色使ったか
  ll colorcount = 0;
  rep(i, N) chmax(colorcount, buckets[i]);
  cout << colorcount << endl;

  // 頂点0を根とする根付き木と考え、頂点0を始点にBFS
  dfs(-1, 0, -1);

  // 答えの出力
  rep(i, N-1){
    cout << colors[edges_pll[i]] << endl;
  }

}