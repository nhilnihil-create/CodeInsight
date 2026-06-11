#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LONG_LONG_MAX / 2;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  ll N;
  cin >> N;
  ll ans = 0;
  for (int i = 1; i <= N; i++) {
    ll tn = N / i * i;
    ans += (i + tn) * (tn / i) / 2;
  }
  cout << ans << endl;
}
