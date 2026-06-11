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

const ll INF = 1e9+10;
const ll MOD = 1e9+7;
const ll LINF = 1e18;

const int maxn = 2005;
ll dp[maxn][maxn]; // s[i]==t[j]のとき、s[i](t[j])を末尾文字にして作れる共通部分列の個数
// s[i]==t[j]であるとき、末尾をs[i]にしてできる共通部分列の個数は(i-1,j-1)までに存在する共通部分列の個数+1となる
// 求める全体での共通部分列の個数は、dpで求めたs[i]==t[j]となるときのそれぞれの共通部分列の個数の和+1({}の場合)となる
ll sub[maxn][maxn]; // sub[i+1][j+1]: dp[i+1][j+1]までの累積和 つまり(i,j)までの共通部分列の個数

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  
  ll n,m; cin>>n>>m;
  vll s(n), t(m);
  rep(i,n) cin>>s[i];
  rep(i,m) cin>>t[i];
  
  rep(i,n){
    rep(j,m){
      if(s[i]==t[j]){
        (dp[i+1][j+1]=sub[i][j]+1)%=MOD;
      }else{
        dp[i+1][j+1]=0;
      }
      
      (sub[i+1][j+1]=(sub[i][j+1]+sub[i+1][j]-sub[i][j]+dp[i+1][j+1]+MOD)%MOD)%=MOD;
    }
  }
  
  ll ans=(sub[n][m]+1)%MOD;
  cout<<ans<<endl;
}