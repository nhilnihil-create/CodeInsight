#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
//typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;


//テンプレート
//辺の構築
template< typename T = int >
struct Edge {
  int from, to;
  T cost;
  int idx;

  Edge() = default;

  Edge(int from, int to, T cost = 1, int idx = -1) : from(from), to(to), cost(cost), idx(idx) {}

  operator int() const { return to; }
};

template< typename T = int >
struct Graph {
  vector< vector< Edge< T > > > g;
  int es;

  Graph() = default;

  explicit Graph(int n) : g(n), es(0) {}

  size_t size() const {
    return g.size();
  }

  void add_directed_edge(int from, int to, T cost = 1) {
    g[from].emplace_back(from, to, cost, es++);
  }

  void add_edge(int from, int to, T cost = 1) {
    g[from].emplace_back(from, to, cost, es);
    g[to].emplace_back(to, from, cost, es++);
  }

  void read(int M, int padding = -1, bool weighted = false, bool directed = false) {
    for(int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b;
      a += padding;
      b += padding;
      T c = T(1);
      if(weighted) cin >> c;
      if(directed) add_directed_edge(a, b, c);
      else add_edge(a, b, c);
    }
  }
};

template< typename T = int >
using Edges = vector< Edge< T > >;

int main(){
    int n,m;
    cin >> n >> m;
    Graph<int>g(n);
    g.read(m,-1,false,true);
    int s,t;
    cin >> s >> t;
    s--;t--;
    int dist[100010][3];
    rep(i,100010)rep(j,3)dist[i][j]=-1;
    queue<P>q;
    q.push(make_pair(s,0));
    dist[s][0]=0;
    while(!q.empty()){
        P p = q.front();q.pop();
        int v = p.first;
        int id = p.second;
        int nid = (id+1)%3;
        for(int x:g.g[v]){
            if(dist[x][nid]!=-1)continue;
            dist[x][nid]=dist[v][id]+1;
            q.push(make_pair(x,nid));
        }
    }
    if(dist[t][0]==-1){
        cout << -1 << endl;
    }
    else{
        cout << dist[t][0]/3 << endl;
    }
    return 0;
}