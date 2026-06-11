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
vi G[100005];
ll dist[100005][3];
const ll INF = 1e9;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main() {
  int n,m;
  cin >>n >> m;
  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--;b--;
    G[a].push_back(b);
  }
  int s,t;
  cin >>s >> t;
  s--;t--;
  Fill(dist,INF);
  dist[s][0] = 0;
  queue<P> q;
  q.push(P(s,0));
  while(!q.empty()){
    int u = q.front().first;
    int k = q.front().second;
    q.pop();
    for(auto v: G[u]){
      if(dist[v][(k+1)%3] != INF)continue;
        dist[v][(k+1)%3] = dist[u][k]+1;
        q.push(P(v,(k+1)%3));
    }
  }
  if(dist[t][0] == INF)cout<<-1<<endl;
  else cout<<dist[t][0]/3<<endl;
  return 0;
}