#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define rep(i, n) for (int i = (int)(0); i < (int)(n); ++i)
#define reps(i, n) for (int i = (int)(1); i <= (int)(n); ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; i--)
#define irep(i, m, n) for (int i = (int)(m); i < (int)(n); ++i)
#define ireps(i, m, n) for (int i = (int)(m); i <= (int)(n); ++i)
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
#define sz(x) int(x.size())

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vs = vector<string>;
using vpll = vector<pair<ll, ll>>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e15;
const int MOD = 1e9+7;
const ll LINF = 1e18;



signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  ll n,t; cin>>n>>t;
  vpll ab(n);
  rep(i,n){
    ll a,b; cin>>a>>b;
    ab[i]={a,b};
  }
  
  vector<vll> dp1(n+1,vll(t+1)), dp2(n+1,vll(t+1));
  rep(i,n){
    ll a=ab[i].first, b=ab[i].second;
    rep(j,t){
      if(j+a<t){
        chmax(dp1[i+1][j+a],dp1[i][j]+b);
      }
      chmax(dp1[i+1][j+1], dp1[i+1][j]);
      chmax(dp1[i+1][j+1], dp1[i][j+1]);
    }
  }
  rrep(i,n){
    ll a=ab[i].first, b=ab[i].second;
    rep(j,t){
      if(j+a<t){
        chmax(dp2[i][j+a],dp2[i+1][j]+b);
      }
      chmax(dp2[i][j+1], dp2[i+1][j+1]);
      chmax(dp2[i][j+1], dp2[i][j]);
    }
  }
  
  ll ans=0;
  irep(i,1,n){
    rep(j,t){
      chmax(ans,dp1[i][j]+dp2[i+1][t-1-j]+ab[i].second);
    }
  }
  cout<<ans<<endl;
}