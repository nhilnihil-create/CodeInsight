#include <vector>
#include <queue>
#include <iostream>
using namespace std;


class TopologicalSort {
public:
  TopologicalSort(int V): V(V), G(V, vector<int>(0)), indeg(V, 0) {}

  void addEdge(int s, int t) {
    G[s].push_back(t);
    indeg.at(t)++;
  }

  vector<int> getSorted() {
    return vs;
  }

  bool sort() {
    queue<int> Q;
    vector<bool> done(V, false);

    for (int i=0; i<V; i++) {
      if (indeg.at(i) == 0) {
        Q.push(i);
        while (Q.size()) {
          int v = Q.front();Q.pop();
          if (done.at(v)) continue;
          done.at(v) = true;
          vs.push_back(v);
          for (auto u: G[v]) {
            if (--indeg.at(u) == 0) Q.push(u);
          }
        }
      }
    }

    return vs.size() == V;
  }

private:
  int V;
  vector<vector<int> > G;
  vector<int> indeg;
  vector<int> vs;
};


#define MAX_E 100001
int V, E;
int S[MAX_E], T[MAX_E];


void input() {
  int s, t;
  cin >> V >> E;
  for (int i=0; i<E; i++) {
    cin >> S[i] >> T[i];
  }
}

void solve() {
  TopologicalSort ts(V);
  for (int i=0; i<E; i++) ts.addEdge(S[i], T[i]);
  ts.sort();
  for (auto v: ts.getSorted()) cout << v << endl;
}

int main() {
  input();
  solve();
  return 0;
}

