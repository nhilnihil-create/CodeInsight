#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll MOD = 1e9+7;

#define vec vector<int>
#define vecll vector<ll>
#define vpair vector<pair<int, int>>
#define vpairll vector<pair<ll, ll>>

#define rep(i,n)         for(int i=(int)0; i<(int)n; i++)
#define REP(i,m,n)       for(int i=(int)m; i<(int)n; i++)
#define arr(var, n)      vecll var(n); rep(i,n){cin >> var[i];}
#define arrll(var, n)    vecll var(n); rep(i,n){cin >> var[i];}
#define all(var)         (var).begin(), (var).end()
#define sortall(var)     sort(all(var))
#define prt(var)         cout << var << endl
#define prtd(n, var)     cout << fixed << setprecision(n) << var << endl
#define prt2(var1, var2) cout << var1 << " " << var2 << endl
#define prtseq(var, n)   rep(i,n){cout << var[i] << " ";} cout << endl;

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
      a--; b--;
      tree[a].push_back(b);
      tree[b].push_back(a);
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

  ll casedfs(int k, int now, int from){
    int can_use_color_num;
    if(from == -1){ // -1 indicates the point has no parent
      can_use_color_num = k-1;
    } else {
      can_use_color_num = k-2;
    }
    if(k<tree[now].size()){ // OK color number is less than points
      return 0;
    } else {
      ll case_num = 1;
      for(int e : tree[now]){
        if(e==from){continue;}

        case_num*=can_use_color_num;
        can_use_color_num--;
        case_num%=MOD;
      }
      for(auto e : tree[now]){
        if(e==from){continue;}

        case_num *= casedfs(k,e,now);
        case_num %= MOD;
      }
      return case_num;
    }
  }

};

int main(void) {
  int n, k;
  cin >> n >> k;

  Graph g(n);
  g.addpath(n-1);

  //prt("path");
  //rep(i,n){prt2("---from : ", i);rep(j,g.tree[i].size()){prt(g.tree[i][j]);}}

  ll ans=k*g.casedfs(k,0,-1);
  ans%=MOD;
  prt(ans);


}
