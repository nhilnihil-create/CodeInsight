#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
using Graph = vector<vector<int>>;

void init(vector<int> &dist) { fill(dist.begin(), dist.end(), -1); }
int main() {
  int n, x, y;
  cin >> n >> x >> y;

  Graph G(n);

  for (int i = 0; i < n - 1; i++) {
    G[i].push_back(i + 1);
    G[i + 1].push_back(i);
  }

  x--;
  y--;
  G[x].push_back(y);
  G[y].push_back(x);

  vector<int> dist(n, -1);  //ある点からdist[i] までの距離

  queue<int> que;

  vector<int> ans(n, 0);

  for (int i = 0; i < n; i++) {
    init(dist);
    que.push(i);
    dist[i] = 0;
    while (!que.empty()) {
      int temp = que.front();
      que.pop();
      for (int nv : G[temp]) {
        if (dist[nv] == -1) {
          que.push(nv);
          dist[nv] = dist[temp] + 1;
        }
      }
    }
    for (int j = 0; j < dist.size(); j++) {
      ans[dist[j]]++;
    }
  }

  for (int i = 1; i < ans.size(); i++) {
    cout << ans[i] / 2 << endl;
  }
}