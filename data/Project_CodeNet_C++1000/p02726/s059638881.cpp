#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
#ifdef __LOCAL
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << x << endl
#define debugArray(x, n)                             \
  cerr << __LINE__ << ": " << #x << " = {";          \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) { \
    cerr << ((hoge) ? "," : "") << x[hoge];          \
  }                                                  \
  cerr << "}" << endl
#else
#define debug(x) (void(0))
#define debugArray(x, n) (void(0))
#endif

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int N, X, Y;
  cin >> N >> X >> Y;
  X--, Y--;
  int distX[N], distY[N];
  const int INF = INT_MAX / 10;
  fill(distX, distX + N, INF);
  fill(distY, distY + N, INF);
  distX[X] = 0;
  distX[Y] = 1;
  distY[Y] = 0;
  distY[X] = 1;
  queue<pair<int, int>> que;
  que.push(make_pair(0, X));
  que.push(make_pair(1, Y));
  while (!que.empty()) {
    int v, d;
    tie(d, v) = que.front();
    que.pop();
    if (distX[v] < d) continue;
    if (v > 0 && distX[v - 1] > distX[v] + 1) {
      distX[v - 1] = distX[v] + 1;
      que.push(make_pair(distX[v - 1], v - 1));
    }
    if (v + 1 < N && distX[v + 1] > distX[v] + 1) {
      distX[v + 1] = distX[v] + 1;
      que.push(make_pair(distX[v + 1], v + 1));
    }
  }
  que.push(make_pair(0, Y));
  que.push(make_pair(1, X));
  while (!que.empty()) {
    int v, d;
    tie(d, v) = que.front();
    que.pop();
    if (distY[v] < d) continue;
    if (v > 0 && distY[v - 1] > distY[v] + 1) {
      distY[v - 1] = distY[v] + 1;
      que.push(make_pair(distY[v - 1], v - 1));
    }
    if (v + 1 < N && distY[v + 1] > distY[v] + 1) {
      distY[v + 1] = distY[v] + 1;
      que.push(make_pair(distY[v + 1], v + 1));
    }
  }
  int cnt[N];
  fill(cnt, cnt + N, 0);
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      int k = min({j - i, distX[i] + distX[j], distY[i] + distY[j]});
      cnt[k]++;
    }
  }
  for (int k = 1; k < N; k++) cout << cnt[k] << endl;
  return 0;
}
