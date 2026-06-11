#include <algorithm>
#include <cstdio>
#include <queue>
#include <set>
#include <vector>
#include <map>

using namespace std;

struct Edge {
  int s;
  int t;
  int w;
  Edge(int s, int t, int w) {
    this->s = s;
    this->t = t;
    this->w = w;
  }
};

bool cmp(const Edge& e1, const Edge& e2) {
  return e1.w > e2.w;
}

vector<Edge> edges;
map<int, vector<Edge>> adj;

int V, E;
int res = 0;
set<int> black;

void input() {
  scanf("%d %d", &V, &E);
  for (int i = 0; i < E; i++) {
    int s, t, w;
    scanf("%d %d %d", &s, &t, &w);
    //edges.emplace_back(s, t, w);
    Edge e(s, t, w);
    adj[s].push_back(e);
    adj[t].push_back(e);
  }
}

class cmp {
public:
  bool operator() (Edge e1, Edge e2) {
    return e1.w < e2.w;
  }
};

void solve() {
  black.insert(0);
  priority_queue<Edge, vector<Edge>, std::function<bool(Edge, Edge)>> pq(cmp);
  for (const Edge& e: adj[0]) {
    pq.push(e);
    //printf("inserting edge %d %d %d to pq\n", e.s, e.t, e.w);
  }
  while (black.size() < V) {
    Edge t(-1, -1, -1);
    bool found = false;
    while (!found) {
      t = pq.top();
      //printf("took edge %d %d %d from pq\n", t.s, t.t, t.w);
      pq.pop();
      found = (black.count(t.s) != black.count(t.t));
    }
    res += t.w;
    //printf("edge %d %d %d included to MST\n", t.s, t.t, t.w);
    int newV = t.s;
    if (black.count(t.s) == 1) {
      newV = t.t;
    }
    for (const Edge& e: adj[newV]) {
      pq.push(e);
      //printf("inserting edge %d %d %d to pq\n", e.s, e.t, e.w);
    }
    black.insert(newV);
  }
}

void output() {
  printf("%d\n", res);
  // for (const auto& x : edges) {
  //   printf("s:%d t:%d w:%d\n", x.s, x.t, x.w);
  // }
}

int main() {
  input();
  solve();
  output();
}