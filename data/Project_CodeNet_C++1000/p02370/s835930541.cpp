#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define RFOR(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define LL long long
#define INF INT_MAX/3

const double EPS = 1e-14;
const double PI  = acos(-1.0);

struct Edge {
  int to;
  int cost;
};

class SingleSourceGraph {
  protected:
    int vertex;
    int start;
    std::vector<long long> dist;
    std::vector<int> prev;
    std::vector<std::vector<Edge> > list;

  public:
    long long inf = LLONG_MAX / 3;

    SingleSourceGraph(int v, int s);

    
    virtual void push(int from, int to, int cost) = 0;

    void dijkstra();
    bool bellman_ford();

    std::vector<long long> get_dist();
    std::vector<int> get_path(int d);
};

SingleSourceGraph::SingleSourceGraph(int v, int s) {
  vertex = v;
  start = s;
  list.resize(vertex);
  dist.resize(vertex);
  prev.resize(vertex);
  for (int i = 0; i < vertex; ++i) {
    dist[i] = inf;
    prev[i] = -1;
  }
  dist[start] = 0;
}

void SingleSourceGraph::dijkstra() {
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > pq;
  pq.push(std::make_pair(0, start));

  while (!pq.empty()) {
    int cost = pq.top().first;
    int v = pq.top().second;
    pq.pop();

    for (int i = 0; i < (int)list[v].size(); ++i) {
      Edge e = list[v][i];
      if (cost + e.cost < dist[e.to] ) {
        prev[e.to] = v;
        dist[e.to] = cost + e.cost;
        pq.push(std::make_pair(dist[e.to], e.to));
      }
    }
  }
}

bool SingleSourceGraph::bellman_ford() {
  bool update = true;
  int cnt = 0;
  while (update) {
    cnt++;
    update = false;
    for (int i = 0; i < vertex; ++i) {
      for (int j = 0; j < (int)list[i].size(); ++j) {
        Edge e = list[i][j];
        if (dist[i] + e.cost < dist[e.to] && dist[i] != inf) {
          if (cnt >= vertex) return true;
          dist[e.to] = dist[i] + e.cost;
          prev[e.to] = i;
          update = true;
        }
      }
    }
  }
  return false;
}

std::vector<long long> SingleSourceGraph::get_dist() {
  return dist;
}

std::vector<int> SingleSourceGraph::get_path(int d) {
  std::vector<int> path;
  int v = d;
  while (v != start) {
    path.push_back(v);
    v = prev[v];
  }
  path.push_back(v);
  std::reverse(path.begin(), path.end());
  return path;
}

class SingleSourceDirectedGraph : public SingleSourceGraph {
  using SingleSourceGraph::SingleSourceGraph;

  public:
    void push(int from, int to, int cost) {
      Edge e;
      e.to = to;
      e.cost = cost;
      list[from].push_back(e);
    }
};

class DAG : public SingleSourceDirectedGraph {
  using SingleSourceDirectedGraph::SingleSourceDirectedGraph;

  public:
  std::vector<int> topological_sort() {
      std::vector<int> intoVertex(vertex, 0);
      std::queue<int> q;

      for (std::vector<Edge> vec: list) {
        for (Edge e: vec) {
          intoVertex[e.to]++;
        }
      }

      for (int i = 0; i < vertex; ++i) {
        if (intoVertex[i] == 0)
          q.push(i);
      }

      std::vector<int> ans;
      while (q.size() > 0) {
        int v = q.front();
        q.pop();
        ans.emplace_back(v);
        for (Edge e: list[v]) {
          intoVertex[e.to]--;
          if (intoVertex[e.to] == 0)
            q.push(e.to);
        }
      }

      return ans;
    }
};

class SingleSourceUndirectedGraph : public SingleSourceGraph {
  using SingleSourceGraph::SingleSourceGraph;

  public:
    void push(int from, int to, int cost) {
      Edge e;
      e.to = to;
      e.cost = cost;
      list[from].push_back(e);

      e.to = from;
      e.cost = cost;
      list[to].push_back(e);
    }

    void prim();
};

void SingleSourceUndirectedGraph::prim() {
  std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int> >, std::greater<std::pair<long long, int> > > pq;

  std::vector<bool> done(vertex, false);

  pq.push(std::make_pair(dist[start], start));

  while (!pq.empty()) {
    int v = pq.top().second;
    pq.pop();

    done[v] = true;

    for (int i = 0; i < (int)list[v].size(); ++i) {
      Edge e = list[v][i];
      if (!done[e.to] && e.cost < dist[e.to]) {
        dist[e.to] = e.cost;
        prev[e.to] = v;
        pq.push(std::make_pair(dist[e.to], e.to));
      }
    }
  }
}

int main() {
  
  int v;
  int e;

  scanf("%d %d", &v, &e);

  DAG g = DAG(v, 0);

  int from, to;

  for (int i = 0; i <  e; i++) {
    scanf("%d %d", &from, &to);
    g.push(from, to, 1);
  }

  std::vector<int> ans = g.topological_sort();
  for (int v: ans) printf("%d\n", v);
}

