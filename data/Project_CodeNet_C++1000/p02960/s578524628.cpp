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

ll dp[100100][13]; // i桁目まで見て、余りがjとなる場合の数

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  string s; cin>>s;
  ll n=s.size();
  
  // 初期化: 0桁目までで余り0となるのは1通り
  // 1桁目の値がnumの時、余りがnumとなるのが+1通り、となるようにするにはdp[0][0]=1と初期化する必要がある
  dp[0][0]=1;
  rep(i,n){
    if(s[i]!='?'){
      ll num=s[i]-'0';
      // i-1桁目までで余りがjとなる通り数から、i桁目がnumのときの場合へ遷移する
      rep(j,13){
        ll rem=(j*10+num)%13;
        (dp[i+1][rem]+=dp[i][j])%=MOD;
      }
    }else{
      // s[i]=='?'なら、numは0~10の全ての場合を数える
      rep(num,10){
        rep(j,13){
          ll rem=(j*10+num)%13;
          (dp[i+1][rem]+=dp[i][j])%=MOD;
        }
      }
    }
  }
  
  cout<<dp[n][5]<<endl;
  
}