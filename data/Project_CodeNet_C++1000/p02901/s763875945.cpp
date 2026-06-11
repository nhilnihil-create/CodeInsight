#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  ll INF = Mod*1000;
  int N,M;
  cin >> N >> M;
  int a[M];
  int key[M];
  for (int i = 0; i < M; i++) {
    key[i] = 0;
  }
  for (int i = 0; i < M; i++) {
    int c;
    cin >> a[i] >> c;
    for (int j = 0; j < c; j++) {
      int d;
      cin >> d;
      d--;
      key[i] += (1 << d);
    }
  }
  ll DP[M+1][(1 << N)];
  for (int i = 0; i <= M; i++) {
    for (int j = 0; j < (1 << N); j++) {
      DP[i][j] = INF;
    }
  }
  for (int i = 0; i <= M; i++) {
    DP[i][0] = 0;
  }
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < (1 << N); j++) {
      DP[i+1][j] = DP[i][j];
    }
    for (int j = 0; j < (1 << N); j++) {
      if (DP[i+1][j | key[i]] > DP[i][j] + a[i]) {
        DP[i+1][j | key[i]] = DP[i][j] + a[i];
      }
    }
  }
  if (DP[M][(1 << N) - 1] == INF) {
    cout << -1 << endl;
  } else {
    cout << DP[M][(1 << N) - 1] << endl;
  }
  return 0;
}