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
ll p[5005];
ll c[5005];
ll step[5005];
ll dp[5005][5005];

// 2周以上なら最大か一歩手前
// 1周目が最大となる場合もある

ll now;
bool visited[5005];
void dfs(ll v, ll cost, ll cnt){
  if(!visited[p[v]]){
    visited[p[v]]=1;
    dp[now][cnt+1]=cost+c[p[v]];
    chmax(step[now],cnt+1);
    dfs(p[v], cost+c[p[v]], cnt+1);
  }
}

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  
  cin>>n>>k;
  rep(i,n) cin>>p[i], p[i]--;
  rep(i,n) cin>>c[i];
  
  rep(i,n){
    rep(j,n) visited[j]=0;
    now=i;
    dfs(i, 0, 0);
  }
  
  // rep(i,5){
  //   rep(j,5) cout<<dp[i][j]<<' ';
  //   cout<<endl;
  // }
  
  // rep(i,n) cout<<step[i]<<' ';
  // cout<<endl;
  
  
  ll ans=-LINF;
  rep(i,n){
    ll ma=-LINF;
    irep(j,1,min(step[i],k)+1) chmax(ma, dp[i][j]);
    if(chmax(ans, ma)){
      if(ans==29544642561){
        // cout<<'x'<<endl;
      }
    }
    
    if(step[i]<=k){
      {
        ll tmp=dp[i][step[i]]*(k/step[i]);
        ll ma=0;
        irep(j,1,k%step[i]+1) chmax(ma, dp[i][j]);
        if(chmax(ans, tmp+ma)){
          // if(ans==29544642561) cout<<'a'<<endl;
        }
      }
      {
        ll tmp=dp[i][step[i]]*(k/step[i]-1);
        if(chmax(ans, tmp+ma)){
          // if(ans==29544642561) cout<<"b"<<endl;
        }
      }
    }
    
  }
  cout<<ans<<endl;
}