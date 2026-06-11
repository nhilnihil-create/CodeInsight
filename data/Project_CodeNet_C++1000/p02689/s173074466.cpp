#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> h(N), ma(N, 0);
  for (int i = 0; i < N; ++i) cin >> h[i];
  for (int i = 0; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    ma[a] = max(ma[a], h[b]);
    ma[b] = max(ma[b], h[a]);
  }
  int res = 0;
  for (int i = 0; i < N; ++i) if (h[i] > ma[i]) ++res;
  cout << res << endl;
}