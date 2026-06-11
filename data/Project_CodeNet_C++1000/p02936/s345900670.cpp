#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;
vector<set<int>> tree;
vector<int> point;

void dfs (int c) {

  // 訪れたことを記録する
  visited[c] = true;

  // 子として繋がっている数だけ繰り返す
  for (int c_ : tree[c]) {

    // 訪れていない場合だけ続ける
    if (visited[c_] == false) {
      
      // ポイントを加える
      point[c_] += point[c];

      // 次に進む
      dfs(c_);

    }

  }

}

int main() {

  int N, Q;
  cin >> N >> Q;

  visited.resize(N);
  tree.resize(N);
  point.resize(N);

  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    tree[a - 1].insert(b - 1);
    tree[b - 1].insert(a - 1);
  }

  for (int i = 0; i < Q; i++) {
    int p, x;
    cin >> p >> x;
    point[p - 1] += x;
  }

  dfs(0);
  
  for (int i = 0; i < N; i++) {
    cout << point[i] << " ";
  }
  cout << endl;

  return 0;

}