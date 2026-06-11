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

ll n,k; 
vll p,c;

bool visited[5005];
ll dp[5005][5005];
ll sub[5005];

ll from;
void dfs(ll v, ll score, ll cnt){
  if(visited[v]){
    dp[from][0]=score;
    sub[from]=cnt;
    return;
  }
  visited[v]=1;
  score+=c[v];
  cnt++;
  dp[from][cnt]=score;
  
  dfs(p[v], score, cnt);
}

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  
  cin>>n>>k;
  p.resize(n); c.resize(n);
  rep(i,n) cin>>p[i], p[i]--;
  rep(i,n) cin>>c[i];
  
  rep(i,n){
    rep(j,n) visited[j]=0;
    from=i;
    dfs(i, 0, 0);
  }
  
  ll ans=-LINF;
  rep(i,n){
    
    // 限界まで回って余った分の中で最大
    {
      ll loop_cnt=k/sub[i];
      ll tmp=dp[i][0]*loop_cnt;
      ll r=k%sub[i];
      ll ma;
      if(loop_cnt>0) ma=0;
      else ma=-LINF;
      rep(j,r) chmax(ma, dp[i][j+1]);
      tmp+=ma;
      chmax(ans, tmp);
    }
    
    // 限界一歩手前まで行ってサイクルの中で最大
    {
      ll loop_cnt=k/sub[i]-1;
      if(loop_cnt>0){
        ll tmp=dp[i][0]*loop_cnt;
        ll ma;
        if(loop_cnt>1) ma=0;
        else ma=-LINF;
        rep(j,sub[i]) chmax(ma, dp[i][j+1]);
        tmp+=ma;
        chmax(ans, tmp);
      }
    }
    
    // 周回しないでサイクル内で最大
    {
      ll ma=-LINF;
      rep(j,min(k,sub[i])) chmax(ma, dp[i][j+1]);
      chmax(ans, ma);
    }
    
  }
  cout<<ans<<endl;
}
