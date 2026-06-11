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



// --------- library end - //


int main(){

  string s = is();
  string t = is();
  ll slen = s.size();
  ll tlen = t.size();

  // とりあえず、tの中に「sの中にない文字」が存在したら NG
  // OK のとき、最悪でも s1つにつきtの文字1つは消化するから、i（必要な文字数）は最大でも |s| * |t| <= 10^10
  // 正確には、|s|*|t|はいかないと思われる。例えばs=ABCD, t=DCBA のとき、ABC[D]AB[C]DA[B]CD[A] で|s|*(|t|)-(|t|-1) となっている

  vector<ll> alphabet_cnts(26, 0); // 各アルファベットが何回登場したか
  // 各アルファベットがs内のどの添字で登場したか
  vector<vector<ll> > alphabet_appearance(26, vector<ll>() );
  rep(i, slen){
    alphabet_cnts[s[i]-'a']++;
    alphabet_appearance[s[i]-'a'].p_b(i);
  }

  // NGケースを処理
  rep(i, tlen){
    if (alphabet_cnts[t[i]-'a'] == 0){
      cout << -1 << endl;
      return 0;
    }
  }

  // s内に登場する各アルファベットの何個目を次に使うか(0-indexed)
  vector<ll> alphabet_nextidx(26, 0);
  ll bef = -1; // 一個前のアルファベットを取る時に使った添字が何であったか（これが今回取りたい添字以上なら、その添字のアルファベットは取れないので、次の周へいく
  ll loop = 0; // 今まで何周したか
  ll t_idx = 0;

  ll last_idx = 0; // 最後に何番目の添字からとったか
  while (t_idx < tlen){
    ll tc_i = t[t_idx] - 'a';
    bool got = false;
    if (alphabet_nextidx[tc_i] < alphabet_cnts[tc_i]){
      REP(nextidx, alphabet_nextidx[tc_i], alphabet_cnts[tc_i]){
        if (bef < alphabet_appearance[tc_i][nextidx]){
          // 今回の周回からまだ取れる
          bef = alphabet_appearance[tc_i][nextidx];
          alphabet_nextidx[tc_i] = nextidx + 1;
          got = true;
          // 最後の文字だったなら、何番目の添字からとったか数えておく
          if (t_idx == tlen-1){
            last_idx = alphabet_appearance[tc_i][nextidx];
          }
          t_idx++; // 次のtを探す
          break;
        }
        // elseの場合は何もしなくていい
        // どこかでアルファベットを取れたらそこで処理が済むし、最後まで取れなければそれで色々リセットされるため
      }
    }
    if (!got){
      // アルファベットが足りなかったか、足りていても添え字が前のものしかなかったか
      loop++;
      // 次に取る添字のリセット
      for (ll &eachnextidx : alphabet_nextidx){
        eachnextidx = 0;
      }
      bef = -1;
    }
  }

  cout << slen * loop + last_idx + 1 << endl;




}