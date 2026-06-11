#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ld  = long double;
using pll = pair<ll, ll> ;
using pld = pair<ld, ld>;
const int INF=1e9+7;
const ll LINF=1LL<<60;
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
void od(double x) { printf("%.15f ", x); }
void os(const string &s) { printf("%s ", s.c_str()); }
void oc(const char &c) { printf("%c ", c); }
auto op = [&](auto p) -> void{ cout << p; };
auto ov = [&](auto vec) -> void{ cout << vec; };
void br() { putchar('\n'); }
 
#define gcd __gcd //llは受け取ってくれない
int lcm(int a, int b){return a / gcd(a, b) * b;}
#define ALL(a) a.begin(),a.end() //sort(ALL(vec));
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define MP(a,b) make_pair(a,b)
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define PB push_back
#define SZ(x) ((int)(x).size) //size()がunsignedなのでエラー避けに

//4近傍（上下左右）
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

// ----- template end ---- //
 
// ------- library ------- //



// ----- library end ----- //



int main() {

  vector<int> squares = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536};

  int N = ii();

  for (auto eachsquare : squares){
    if (N == eachsquare){
      os("No"); br();
      return 0;
    }
  }

  os("Yes"); br();

  //3までを構築
  oi(N+1); oi(N+2); br();
  oi(N+2); oi(3); br();
  oi(3); oi(1); br();
  oi(1); oi(2); br();
  oi(2); oi(N+3); br();
  if(N==3){
    return 0;
  }
  //偶奇どちらでも行う構築
  //N-3を2で割って切り捨てた数（{n, n+1}の組の数）だけ行う
  REP(i, 0, (N-3)/2 ){
    int j = i*2;
    oi(4+j); oi(1); br();
    oi(1); oi(4+j+1); br();
    oi(4+j+1); oi(N+4+j); br();
    oi(4+j); oi(N+4+j+1); br();
  }

  //奇数
  if(N%2==1){
    return 0;
  }
  else{ //最後に残った偶数（N）の処理
    //残ったNは1, 任意の同じbit桁数の数(aとする), そしてbと繋ぐ
    //aが決まれば、bは一意に定まる(b = )
    //Nは2^kじゃないので、aはsquaresからNより小さい最大のものを選ぶ
    int a = 0;
    for(auto eachs : squares){
      if (eachs > a && eachs < N){
        a = eachs;
      }
    }
    int b = 1 ^ N ^ a;
    
    oi(N); oi(a); br();
    oi(b); oi(N*2); br();
  }


  
// -- main() end -- //
}
