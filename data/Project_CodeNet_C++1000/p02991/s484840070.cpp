#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define show(x) cout<<#x<<" = "<<x<<endl;
#define print(x)cout<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;

const ll inf = 10010010001LL;
vi G[100100];
ll d[100100][3];

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main() {
  int n,m;
  cin >> n >> m;
  rep(i,m){
    int u,v;
    cin >> u >> v;
    u--;v--;
    G[u].push_back(v);
    //G[v].push_back(u);
  }
  int s,t;
  cin >> s >> t;
  s--;t--;
  Fill(d,inf);
  queue<P> q; 
  d[s][0] = 0;
  q.push(P(s,0));
  while(!q.empty()){
    auto up = q.front();
    q.pop();
    for(auto v:G[up.fi]){
      int z = (up.se+1)%3;
      if(d[v][z] > d[up.fi][up.se]+1){
        d[v][z] = d[up.fi][up.se]+1;
        q.push(P(v,z));
      }
    }
  }
  // rep(i,n){
  //   rep(k,3)cout<<d[i][k]<<" ";
  //   cout<<endl;
  // }
  ll ans = d[t][0] == inf?-1:d[t][0]/3;
  cout<<ans<<endl;
  return 0;
}