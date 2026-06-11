#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll N, K; cin >> N >> K;
  vector<ll> P(N), C(N);
  for (auto& x: P) cin >> x, x--;
  for (auto& x: C) cin >> x;
  ll res = -1e18;
  for (int i = 0; i < N; i++) {
    vector<ll> sum;
    ll t = 0;
    int idx = i;
    do {
      t += C[idx];
      sum.push_back(t);
      idx = P[idx];
    } while (idx - i);
    for (int j = 0; j < min<int>(K, sum.size()); j++) res = max(res, sum[j]);
    ll sz = sum.size();
    for (int j = 0; j < sz; j++) {
      if (j < K % sz) {
        res = max(res, K / sz * sum.back() + sum[j]);
      } else {
        int cnt = K / sz - 1;
        if (cnt < 0) break;
        res = max(res, cnt * sum.back() + sum[j]);
      }
    }
  }
  cout << res << endl;
}
