#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1001001001
#define LINF 1001001001001001001
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define bit(n) (1LL<<(n))
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LLP;

/*
    Dijkstra's Algorithm (Single Source Shortest Path)
        - for directed graph
        - NO edges have negative cost
        - 0-indexed vertexes
 */

class Dijkstra {
    private:
        vector< vector<LLP> > G;
        vector<ll> cost;
        vector<ll> par;
        priority_queue<LLP, vector<LLP>, greater<LLP> > que;

    public:
        Dijkstra(ll n, vector<vector<ll>> g, ll s);
        ll  getCost(ll target);
        vector< vector<ll> > getPath(ll  target);
};

// n: |V|
// g: [point_from, point_to, cost] (directed graph)
// s: start point
Dijkstra::Dijkstra(ll n, vector<vector<ll>> g, ll s) {
    for (ll  i = 0; i < n; i++) {
        G.push_back(vector<LLP>());
        cost.push_back(-1);
        par.push_back(-1);
    }

    // create adj-Graph
    for (ll i = 0; i < g.size(); i++) {
        G[g[i][0]].push_back(make_pair(g[i][1], g[i][2]));
    }

    // initialize
    cost[s] = 0;
    par[s] = s;
    que.push(make_pair(cost[s], s));

    while (!que.empty()) {
        LLP p = que.top();
        que.pop();

        if (cost[p.second] < p.first) continue;
        for (int i = 0; i < G[p.second].size(); i++) {
            if (cost[G[p.second][i].first] < 0 || cost[G[p.second][i].first] > cost[p.second] + G[p.second][i].second) {
                cost[G[p.second][i].first] = cost[p.second] + G[p.second][i].second;
                par[G[p.second][i].first] = p.second;
                que.push(make_pair(cost[G[p.second][i].first], G[p.second][i].first));
            }
        }
    }
}

// returns the minimum cost from the start point to the target.
// (if there is no path to the target, this returns -1.)
// (if the target is the start point, this returns 0.)
ll Dijkstra::getCost(ll target) {
    return cost[target];
}


// returns a list of path: Array of [point_from, point_to, cost].
// (if there is no path to the target or the target is the start point, this returns an empty vector.)
vector< vector<ll> > Dijkstra::getPath(ll target) {

    vector< vector<ll> > reversePath = vector< vector<ll> >(0);

    if (cost[target] <= 0) return reversePath;
    
    ll now_p = target;
    while (par[now_p] != now_p) {
        vector<ll> temp(3);
        temp[0] = par[now_p];
        temp[1] = now_p;
        temp[2] = cost[now_p] - cost[par[now_p]];
        reversePath.push_back(temp);
        now_p = par[now_p];
    }

    vector< vector<ll> > path = vector< vector<ll> >(0);
    for (ll i = reversePath.size() - 1; i >= 0; i--) path.push_back(reversePath[i]);

    return path;
}

int main() {
  
  int N, K, C;
  cin >> N >> K >> C;
  string S;
  cin >> S;

  if (C == 0) {
    int count = 0;
    rep(i,S.size()) if (S[i] == 'o') count++;
    if (count == K) {
      rep(i,S.size()) if (S[i] == 'o') cout << (i + 1) << endl;
    }
    return 0;
  }

  vector<vector<ll>> es, eg;
  rep(i,S.size()) {
    if (S[i] == 'o') {
      vector<ll> e(3);
      e[0] = i + C + 1;
      e[1] = i + C + 1 + C + 1;
      e[2] = 1;
      es.push_back(e);
      swap(e[0], e[1]);
      eg.push_back(e);
    }
  }
  rep(i,N+2*C+1) {
      vector<ll> e(3);
      e[0] = i;
      e[1] = i + 1;
      e[2] = 1;
      es.push_back(e);
      swap(e[0], e[1]);
      eg.push_back(e);
  }

  Dijkstra tree_s(N + 2 * C + 2, es, 0), tree_g(N + 2 * C + 2, eg, N + 2 * C + 1);
  set<int> passSet;
  rep(i,N) {
    if (passSet.find(i - C - 1) != passSet.end()) passSet.erase(i - C - 1);
    if (S[i] == 'x') continue;
    ll cost = tree_s.getCost(i + C + 1) + 1 + tree_g.getCost(i + C + 1 + 1);
    if (passSet.size() == 0 && cost > N + 2 * C + 1 - C * K) cout << (i + 1) << endl;
    ll cost_jump = tree_s.getCost(i + C + 1) + 1 + tree_g.getCost(i + C + 1 + C + 1);
    if (cost_jump <= N + 2 * C + 1 - C * K) passSet.insert(i);
  }

  return 0;
}