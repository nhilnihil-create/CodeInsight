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

ll dp[100005][2]; // i桁目まで見たとき、 j==0: i桁目まで一致している、j==1: 未満であることが確定している 通り数

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  string s; cin>>s;
  ll n=s.size();
  
  dp[0][0]=1;
  
  rep(i,n){
    // a+b == 0
    if(s[i]=='0'){
      dp[i+1][0]=dp[i][0]; // s[i]==0 の時、 a+b==0 なので、i桁目まで一致している通り数 *1 となる
      dp[i+1][1]=dp[i][1]; // 未満となることが確定している通り数を引き継ぐ これは全てのブロックで計算される
    }else{
      // s[i]==1 の時、a+b==0 にする → 未満になる
      // 今見ている桁まで同じ値である数が、未満になる数として通算できる
      dp[i+1][1]=(dp[i][0]+dp[i][1])%MOD;
    }
    
    // a+b == 1
    if(s[i]=='0'){
      (dp[i+1][1]+=dp[i][1]*2%MOD)%=MOD; // a+b==1 とできるのは2通りなので *2
    }else{
      (dp[i+1][0]+=dp[i][0]*2%MOD)%=MOD;
      (dp[i+1][1]+=dp[i][1]*2%MOD)%=MOD;
    }
  }
  ll ans=(dp[n][0]+dp[n][1])%MOD;
  
  cout<<ans<<endl;
}