#include <iostream>
#include <queue>
#include <vector>         
using namespace std;

int main() {
  int n; cin >> n;
  int m = n * (n-1) / 2;

  auto make_game = [&](int i, int j) {
    if (i > j) swap(i, j);
    return (n-1+n-i)*i/2 + (j-i-1);
  };

  vector<int> t[m];
  int degree[m] = {};
  for (int i = 0; i < n; i++) {
    int a[n-1];
    for (int j = 0; j < n-1; j++) {
      cin >> a[j];
      a[j]--;
    }
    for (int j = 0; j < n-2; j++) {
      int g = make_game(i, a[j]);
      int h = make_game(i, a[j+1]);
      t[g].push_back(h);
      degree[h]++;
    }
  }

  queue<int> que;
  int dist[m];
  for (int i = 0; i < m; i++) {
    if (degree[i] == 0) {
      que.push(i);
      dist[i] = 1;
    }
  }

  int ans = 0;
  while (!que.empty()) {
    int g = que.front(); que.pop();
    for (int h : t[g]) {
      if (--degree[h] == 0) {
        que.push(h);
        dist[h] = dist[g] + 1;
        ans = max(ans, dist[h]);
      }
    }
  }

  for (int i = 0; i < m; i++) {
    if (degree[i]) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
}