#include <bits/stdc++.h>
#define exrep(i, a, b) for(long long i = a; i <= b; i++)
#define rep(i,n)for(long long i=0;i<(long long)(n);i++)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
const ll MOD=1e9+7;
const ll INF=1e18;
const int MAX=110000;
const double pi=acos(-1);
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

ll gcd(ll x, ll y){
  if(x%y==0)return y;
  return gcd(y,x%y);
}
ll lcm(ll x,ll y){
  return x/gcd(x,y)*y;
}
ll n,m;
ll s,t;
ll dist[110000][3];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false); 
  
  cin >> n >> m;
  vector<vector<ll>> G(n); 
  rep(i,m){
    ll u,v;
    cin >> u >> v;
    u--;
    v--;
    G[u].push_back(v);
  }
  cin >> s >> t;
  s--;
  t--;
  
  
  rep(i,n){
    rep(j,3){
      dist[i][j]=-1;
    }
  }
  dist[s][0]=0;
  queue<P>q;
  q.push({s,0});
  while(!q.empty()){
    auto now=q.front();
    q.pop();
    ll v=now.first;
    ll p=now.second;
    for(auto nv:G[v]){
      ll np=(p+1)%3;
      if(dist[nv][np]==-1){
        dist[nv][np]=dist[v][p]+1;
        q.push({nv,np});
      }
    }
  }
  if(dist[t][0]==-1){
    cout << -1 << endl;
    return 0;
  }
  cout << dist[t][0]/3 << endl;
    
  
}