#include <bits/stdc++.h>
using namespace std;
static const int MAX = 100000;
static const int NIL = -1;

int n, m;
vector<int> color(MAX, NIL);
vector<vector<int>> M(MAX);

void dfs(int i, int id) {
  int size = M[i].size();
  color[i] = id;
  for (int j = 0; j < size; j++) {
    if (color[M[i][j]] == NIL) {
      color[M[i][j]] = id;
      dfs(M[i][j], id);
    }
  }
}

void assignColor() {
  int id = 1;
  for (int i = 0; i < n; i++) {
    if (color[i] == NIL) dfs(i, id++);
  }
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int id, f;
    cin >> id >> f;
    M[id].push_back(f);
    M[f].push_back(id);
  }
  int qn;
  cin >> qn;
  vector<vector<int>> q(qn, vector<int>(2));
  for (int i = 0; i < qn; i++) {
    cin >> q[i][0] >> q[i][1];
  }

  assignColor();

  for (int i = 0; i < qn; i++) {
    if (color[q[i][0]] == color[q[i][1]]) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
}
