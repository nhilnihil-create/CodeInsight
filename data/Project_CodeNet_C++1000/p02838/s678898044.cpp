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

ll llpow(ll a, ll b){
    if(b == 0){
        return 1;
    }
    ll ans = llpow(a, b / 2);
    ans = ans * ans % MOD;
    if(b % 2 == 1){
        ans = ans * a % MOD;
    }
    return ans;
}


// --------- library end - //


int main(){

  ll N = il();
  vector<ll> as;
  as.push_back(0); // cumsumを使うので今回は1-indexed
  rep(i, N){
    as.push_back(il());
  }

  // [1, i] 区間について、各桁（0 ~ max60) に < 0, 1 > が何個あるか
  vector<vector<pll> > cumsum_eachdig_01s(N+1, vector<pll>(60, m_p(0, 0) ) );

  REP(i, 1, N+1){
    // Ai の各桁 が0ならfirstに++, 1ならsecondに++
    ll a = as[i];
    rep(d, 60){
      if (a % 2 == 0){
        cumsum_eachdig_01s[i][d].first = cumsum_eachdig_01s[i-1][d].first + 1;
        cumsum_eachdig_01s[i][d].second = cumsum_eachdig_01s[i-1][d].second;
      }
      else{
        cumsum_eachdig_01s[i][d].first = cumsum_eachdig_01s[i-1][d].first;
        cumsum_eachdig_01s[i][d].second = cumsum_eachdig_01s[i-1][d].second + 1;
      }
      a /= 2;
    }
  }

  // 各桁に 1 が何個あるか
  vector<ll> anss(60, 0);

  REP(i, 1, N){
    // Ai の各桁 が0なら1の数を足す, 1なら0の数を足す
    // i=N については見なくていい
    ll a = as[i];
    rep(d, 60){
      ll zerocnt = cumsum_eachdig_01s[N][d].first - cumsum_eachdig_01s[i][d].first;
      ll onecnt = cumsum_eachdig_01s[N][d].second - cumsum_eachdig_01s[i][d].second;
      if (a % 2 == 0){
        anss[d] = (anss[d] + onecnt) % MOD;
      }
      else{
        // as[i]のd桁目が1の場合、0が1になる
        anss[d] = (anss[d] + zerocnt) % MOD;
      }
      a /= 2;
    }
  }

  // 答え
  ll ans = 0;
  ll two_xjou = 1;
  rep(d, 60){
    ans += two_xjou * anss[d] % MOD;
    ans %= MOD;
    two_xjou = two_xjou * 2 % MOD;
  }

  cout << ans << endl;


}