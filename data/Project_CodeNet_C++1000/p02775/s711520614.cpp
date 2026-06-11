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

// reference: https://betrue12.hateblo.jp/entry/2020/02/17/020628

ll dp[1001001][2];
signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  string s; cin>>s;
  s='0'+s;
  ll n=s.size();
  vll a(n);
  rep(i,n){
    a[i]=s[i]-'0';
  }
  
  rep(i,n+1) rep(j,2) dp[i][j]=LINF;
  dp[0][0]=0;
  rep(i,n){
    chmin(dp[i+1][0],dp[i][0]+a[i]);
    chmin(dp[i+1][1],dp[i][0]+a[i]+1);
    chmin(dp[i+1][0],dp[i][1]+10-a[i]);
    chmin(dp[i+1][1],dp[i][1]+10-a[i]-1);
  }
  ll ans=dp[n][0];
  cout<<ans<<endl;
}