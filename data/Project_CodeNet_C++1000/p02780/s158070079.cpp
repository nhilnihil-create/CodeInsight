#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
  int N, K; cin >> N >> K;
  vector<double> D(N+1, 0);
  for (int i = 1; i<=N; i++) {
    int p; cin >> p;
    double e = 0;
    rep(j,p) e += j+1;
    e /= p;
    D.at(i) = D.at(i-1) + e;
  }

  double ma = 0;
  for (int i = 0; i + K <= N; i++) {
    if (ma < D[i+K] - D[i]) ma = D[i+K] - D[i];
  }
  cout << fixed << setprecision(12);
  cout << ma << endl;
}
