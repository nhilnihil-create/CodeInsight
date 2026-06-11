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


ll llpow(ll a, ll b){
    if(b == 0){
        return 1;
    }
    ll ans = llpow(a, b / 2);
    ans = ans * ans; //% MOD (MODつけたい場合のコピー用)
    if(b % 2 == 1){
        ans = ans * a; //% MOD (MODつけたい場合のコピー用)
    }
    return ans;
}

// --------- library end - //


// - main() -------------- //

int main(){

  string S = is();
  int N = S.size();

  int DP[200001][5];
  // DP[i][j:1~4] i文字目まで見て、最後にj文字をひとまとめにした場合の最大のK
  // DP[i][0] は実際にはありえない（0文字選ぶ場合はない）。添字を分かりやすくするため1-indexedとするだけで、DP[i][0]は使わない

  rep(j, 5){
    DP[0][j] = 0;
  }

  rep(j, 5){
    DP[1][j] = 0;
    if (j==1) {
      DP[1][j] = 1;
    }
  }

  // ここからは普通に遷移をしていくが、
  // iが小さいうちは、遷移元のマスが存在しない場合があることに注意

  for (int i = 2; i < 200001; i++){
    if (i > N) break;
    for (int j = 1; j < (min(i+1, 5)); j++){
      // min()は左端の方を処理するためのもの。最高でもi個しか取れないのでこうなる
      if (i-j==0){
        // [abc]caiek... のように、左端をとる場合なので、そこまでの最大分割数は必ず 1
        DP[i][j] = 1;
      }
      else{
        // 左側に隣り合う文字列がある場合
        // 長くなりすぎるとアレなので、chmaxしていく
        int tmp = 0;
        // S[i-j+1, i] と S[i-j+1-k, i-j] が異なれば +1。同じであれば +-0……ではなく、その区切り方はNGなので、0とする。i-jがゼロ未満ならその比較はせず、0とする。
        for (int k = 1; k < 5; k++){
          if (i-j+1-k <= 0){
            chmax(tmp, 0); // 意味ないが思考の整理のため入れた
          }
          else if (j==k && S.substr(i-j+1-k-1, k) == S.substr(i-j, j) ){
            // 左隣の文字列と一致してしまった場合、0となる
            chmax(tmp, 0); // 同上
          }
          else{
            chmax(tmp, DP[i-j][k]+1);
          }
        }
        DP[i][j] = tmp;
      }
    }
  }

  int ans = 0;
  REP(j, 1, 5){
    chmax(ans, DP[N][j]);
  }

  oi(ans);


// ---------- main() end - //
}