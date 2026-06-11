#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<int> edges[200000];
int64_t num[200000];

void dfs(int i, int p) {
  for (int j : edges[i])
    if (j != p) {
      num[j] += num[i];
      dfs(j, i);
    }
}

int main() {
  cin >> N >> Q;
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    edges[a - 1].push_back(b - 1);
    edges[b - 1].push_back(a - 1);
  }
  for (int i = 0; i < Q; i++) {
    int p, x;
    cin >> p >> x;
    num[p - 1] += x;
  }
  dfs(0, -1);
  for (int i = 0; i < N; i++) {
    if (i) cout << " ";
    cout << num[i];
  }
  cout << endl;
  return 0;
}
