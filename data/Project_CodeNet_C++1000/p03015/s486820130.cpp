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
using tll = tuple<ll,ll,ll>;
using vtll = vector<tuple<ll,ll,ll>>;
using vb = vector<bool>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e9;
const ll MOD = 1e9+7;
const ll LINF = 1e18;

ll dp[1001001][2];

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  string s; cin>>s;
  ll n=s.size();
  
  dp[0][0]=1;
  rep(i,n) rep(j,2){
    if(j==0){
      if(s[i]=='0'){
        // s[i]==0 ... a==0,b==0 の1通り
        (dp[i+1][j]+=dp[i][j])%=MOD;
      }else{
        // s[i]==1 ... (1,0) ならj==0のまま、(0,0)ならj==1に遷移
        (dp[i+1][j]+=dp[i][j]*2)%=MOD;
        (dp[i+1][1]+=dp[i][j])%=MOD;
      }
    }else{
      // 0 or 1どちらでも
      (dp[i+1][j]+=dp[i][j]*3)%=MOD;
    }
  }
  ll ans=(dp[n][0]+dp[n][1])%MOD;
  cout<<ans<<endl;
}