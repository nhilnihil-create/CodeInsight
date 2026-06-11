#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll MOD = 1e9+7;

#define vec vector<int>
#define vecll vector<ll>
#define vpair vector<pair<int, int>>
#define vpairll vector<pair<ll, ll>>

#define rep(i,n)   for(int i=(int)0; i<(int)n; i++)
#define REP(i,m,n) for(int i=(int)m; i<(int)n; i++)
#define all(var)     (var).begin(), (var).end()
#define prt(var)     cout << var << endl
#define prtd(n, var)  cout << fixed << setprecision(n) << var << endl
#define prt2(var1, var2) cout << var1 << " " << var2 << endl

//----------------------------------------------------------------
class Graph{

public:
  vector<vector<int>> tree;
  vector<int> check; // For DFS
  vector<ll> dist;   // For BFS
  queue<int> q; // For BFS

  Graph(int n){
    tree.resize(n);
    init(n);
  }
  ~Graph(){}

  void addpath(int m){
    int a, b;
    rep(i,m){
      cin >> a >> b;
      a = (a-1)*3; b = (b-1)*3;
      tree[a].push_back(b+1);
      tree[a+1].push_back(b+2);
      tree[a+2].push_back(b);
    }
  }

  void init(int n){
    check.assign(n, false);
    dist.assign(n, -1);
  }
  void resetCheck(){
    rep(i,check.size()){
      check[i] = false;
    }
  }

  void dfs(int v){
    check[v] = true;

    for(auto next_v : tree[v]){
      if(check[next_v]) continue;
      dfs(next_v);
    }
  }

  void bfs(int v){
    dist[v] = 0;
    q.push(v);

    while(!q.empty()){
      int cur_v = q.front();
      q.pop();

      for(int next_v : tree[cur_v]){
        if(dist[next_v] != -1){
          continue;
        }

        dist[next_v] = dist[cur_v] + 1;
        q.push(next_v);
      }
    }
  }
};

int main(void) {
  int n, m;
  cin >> n >> m;

  Graph g(3*n);
  g.addpath(m);

  int s, t;
  cin >> s >> t;
  s = (s-1)*3;
  t = (t-1)*3;

  //prt("path check");
  //rep(i,n){prt2("---from : ", i);rep(j,g.tree[i].size()){prt(g.tree[i][j]);}}

  //prt("Distance");
  //rep(i,n){prt2(i, g.dist[i]);}

  g.bfs(s);
  if(g.dist[t] == -1){prt(-1); return 0;}
  prt(g.dist[t]/3);
  //prt("check"); rep(i,n){prt2(i, g.dist[i]);}

}
