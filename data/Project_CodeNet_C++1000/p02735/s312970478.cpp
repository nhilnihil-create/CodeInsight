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

char G[105][105];

const ll dy[] = {0, 1, 0, -1, -1, 1, 1, -1};
const ll dx[] = {1, 0, -1, 0, 1, 1, -1, -1};

inline bool inside(ll y, ll x, ll H, ll W) {
    return (y >= 0 && x >= 0 && y < H && x < W);
}

ll cost[105][105];

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  
  ll h,w; cin>>h>>w;
  
  rep(i,h) rep(j,w) cin>>G[i][j];
  
  rep(i,h) rep(j,w) cost[i][j]=LINF;
  if(G[0][0]=='#') cost[0][0]=1;
  else cost[0][0]=0;
  
  priority_queue<tuple<ll,ll,ll,ll>, vector<tuple<ll,ll,ll,ll>>, greater<tuple<ll,ll,ll,ll>>> q;
  q.emplace(cost[0][0],0,0,cost[0][0]);
  
  
  while(!q.empty()){
    ll c,y,x,prev;
    tie(c,y,x,prev) = q.top(); q.pop();
    if(cost[y][x]<c) continue;
    rep(i,2){
      ll ny=dy[i]+y, nx=dx[i]+x;
      if(inside(ny,nx,h,w)){
        if(G[ny][nx]=='#'){
          if(prev==1){
            if(chmin(cost[ny][nx], c)) q.emplace(c,ny,nx,1);
          }else{
            if(chmin(cost[ny][nx], c+1)) q.emplace(c+1,ny,nx,1);
          }
        }else{
          if(chmin(cost[ny][nx], c)) q.emplace(c,ny,nx,0);
        }
      }
    }
  }
  
  cout<<cost[h-1][w-1]<<endl;
  
  
}