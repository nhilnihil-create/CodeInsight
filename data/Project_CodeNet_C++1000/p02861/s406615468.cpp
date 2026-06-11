#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int facctorialMethod(int k) {
  int sum = 1;
  for (int i = 1; i <= k; ++i) {
    sum *= i;
  }
  return sum;
}

int main() {
  int n;
  cin >> n;
  vector<P> p;
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    p.push_back(make_pair(x, y));
  }

  vector<vector<double> > dist(n, vector<double>(n));  // 各都市間の所要時間
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int x = p[i].first - p[j].first;
      int y = p[i].second - p[j].second;
      dist[i][j] = sqrt(x * x + y * y);
    }
  }

  vector<int> order(n);
  rep(i, n) order[i] = i;

  double ans = 0;
  do {
    /* 順序 order についての所要時間を計算 */
    double temp_dist = 0;
    for (int i = 1; i < n; ++i) {
      temp_dist += dist[order[i - 1]][order[i]];
    }
    ans += temp_dist;
  } while (next_permutation(order.begin(), order.end()));

  ans = ans / facctorialMethod(n);

  cout << fixed << setprecision(15) << ans << endl;
  return 0;
}