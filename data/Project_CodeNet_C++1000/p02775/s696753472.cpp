#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define rep(i, n) for (long long i = (long long)(0); i < (long long)(n); ++i)
#define reps(i, n) for (long long i = (long long)(1); i <= (long long)(n); ++i)
#define rrep(i, n) for (long long i = ((long long)(n)-1); i >= 0; i--)
#define rreps(i, n) for (long long i = ((long long)(n)); i > 0; i--)
#define irep(i, m, n) for (long long i = (long long)(m); i < (long long)(n); ++i)
#define ireps(i, m, n) for (long long i = (long long)(m); i <= (long long)(n); ++i)
#define SORT(v, n) sort(v, v + n);
#define REVERSE(v, n) reverse(v, v+n);
#define vsort(v) sort(v.begin(), v.end());
#define all(v) v.begin(), v.end()
#define mp(n, m) make_pair(n, m);
#define cout(d) cout<<d<<endl;
#define coutd(d) cout<<std::setprecision(10)<<d<<endl;
#define cinline(n) getline(cin,n);
#define replace_all(s, b, a) replace(s.begin(),s.end(), b, a);
#define PI (acos(-1))
#define FILL(v, n, x) fill(v, v + n, x);
#define sz(x) long long(x.size())

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vs = vector<string>;
using vpll = vector<pair<ll, ll>>;
using vtp = vector<tuple<ll,ll,ll>>;
using vb = vector<bool>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e9;
const ll MOD = 1e9+7;
const ll LINF = 1e18;

// https://betrue12.hateblo.jp/entry/2020/02/17/020628

ll dp[1001001][2]; // i桁まで見て、これまでピッタリ払っている多くorはらっている、場合に発生する支払い・お釣りの最小合計枚数
// j=0 ピッタリ払っている状態からはお釣りは発生しない。自身が払う枚数だけ遷移先に加算される
// j=1 上位桁で1枚多く払っている状態からは何枚お釣りを受け取るかのみを考慮する
// (少し考えればわかるが、上位桁で1枚多く払っているのならその桁で自身が1枚払う必要はない)

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  
  string s; cin>>s;
  s='0'+s;
  ll n=s.size();
  
  rep(i,n+1) rep(j,2) dp[i][j]=LINF;
  dp[0][0]=0;
  rep(i,n){
    ll now=s[i]-'0';
    chmin(dp[i+1][0],dp[i][0]+now);      // ピッタリ払う
    chmin(dp[i+1][1],dp[i][0]+now+1);    // 1枚多く支払うので+1
    chmin(dp[i+1][0],dp[i][1]+10-now);   // 上位桁が1枚多い状態から払わない => お釣りとして10-nowもらう
    // NOTE: この一行がない場合
    // 例として95を考える
    // 100円払って、5円お釣りをもらう、1+5=6が最小
    // この一行がないと、100の位で1枚払い、10の桁ではお釣りを貰わず余りを1の位に補填する、という場合を考慮できない
    // 上記の場合が抜けると、105円払って10円貰う場合、6+1=7がが最小となり辻褄が合わない
    chmin(dp[i+1][1],dp[i][1]+10-now-1); // 上位桁が1枚多い状態から払わないが、以降の桁のために1枚受け取らず残しておく => お釣りとして10-now-1もらう
  }
  
  cout<<dp[n][0]<<endl;
  
}