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
#define REP(i,m,n) for(ll i=(ll)(m) ; i < (ll)(n) ; i++ )
#define DREP(i,m,n) for(ll i=(ll)(m) ; i > (ll)(n) ; i-- )
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



// --------- library end - //


int main(){

  string s = is();
  string t = is();
  ll slen = s.size();

  string ds = s + s;
  ll dslen = slen * 2;

  // next[i][a~z] := これまでに[i-1]番目までのアルファベットを取り、次に[i]番目から探し始めるとき、アルファベット [a]~[z] が、最初に（i番目を含んでそれより右の領域において最も左側に）出るのが next[i][a~z]番目であることを示す
  // next[][] = dslen のとき、そのアルファベットはその添字以降もう出ないことを表す
  vector<vector<ll> > next(dslen+1, vector<ll>(26, dslen) );

  // 出現位置の表（next[][]）を作成する
  DREP(i, dslen-1, -1){
    // i番目に出るアルファベット以外は、i+1番目以降に出る位置をそのまま入れればいい
    rep(j, 26) next[i][j] = next[i+1][j];

    // i番目に出るアルファベットは、i番目以降最初にi番目に出る（当たり前）
    next[i][ ds[i]-'a' ] = i;
  }

  // next[][] を用いて、今何文字目まで使ったかをカウントしていく
  ll used = -1;
  for (char c : t){
    // used % slen で、何文字目のアルファベットまで使ってあるかを求められる -> used+1で「何文字目から見るか」
    // ∵ n文字の文字列を繰り返す = n文字ごとにリセットされる = mod nの世界と同じ
    if (next[(used+1) % slen][c-'a'] == dslen){
      // 今後その文字が出ないという意味だから、構成不可
      cout << -1 << endl;
      return 0;
    }
    ll step = next[(used+1) % slen][c-'a'] - ((used+1) % slen) + 1; // 何文字進むか
    used += step;
  }

  // 答えは「何文字目まで使ったか」だが、used は 0-indexed なので、+1 する
  cout << used + 1 << endl;
  
  
  
}