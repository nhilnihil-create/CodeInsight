#include <bits/stdc++.h>
using namespace std;

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int K, Q; cin >> K >> Q;
  int D[K];
  for (auto i = 0; i < K; i++) cin >> D[i];
  int n, x, m;
  long a, s1, s2, v;
  for (auto i = 0; i < Q; i++) {
    cin >> n >> x >> m;
    s1 = 0; s2 = 0;
    for (auto j = 0; j < K; j++) {
      v = D[j]%m == 0 ? m : D[j]%m;
      s1 += v;
      if (j < (n - 1)%K) s2 += v;
    }
    a = x%m + (n - 1)/K*s1 + s2;
    cout << (n - 1) - a/m << endl;
  }
}