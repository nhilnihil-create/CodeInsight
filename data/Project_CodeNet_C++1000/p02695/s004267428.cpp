#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

void combination(Graph& graph, vector<int> selected, vector<int> rest, int r) {
  if (selected.size() == r) {
    graph.push_back(selected);
    return;
  }
  if (selected.size() + rest.size() < r) return;
  int e = rest.at(rest.size() - 1);
  rest.pop_back();
  combination(graph, selected, rest, r);
  selected.push_back(e);
  combination(graph, selected, rest, r);
}

int main() {
  int N, M, Q;
  cin >> N >> M >> Q;
  vector<vector<int>> ABCD(Q);
  rep(i, Q) {
    vector<int> abcd(4);
    cin >> abcd.at(0) >> abcd.at(1) >> abcd.at(2) >> abcd.at(3);
    ABCD.at(i) = abcd;
  }

  int size = M + N - 1;
  vector<int> rest(size);
  rep(i, size) rest.at(i) = i + 1;

  Graph graph(0);
  combination(graph, {}, rest, N);

  int ans = 0;
  for (auto vec : graph) {
    vector<int> row(M + N, true);
    for (auto i : vec) {
      row.at(i) = false;
    }
    vector<int> A;
    int a = 0;
    for (auto b : row) {
      if (b)
        a++;
      else
        A.push_back(a);
    }

    int d = 0;
    for (auto abcd : ABCD) {
      int a = abcd.at(0);
      int b = abcd.at(1);
      int c = abcd.at(2);

      if (A.at(b - 1) - A.at(a - 1) == c) {
        d += abcd.at(3);
      }
    }
    ans = max(ans, d);
  }
  cout << ans << endl;
  return 0;
}
