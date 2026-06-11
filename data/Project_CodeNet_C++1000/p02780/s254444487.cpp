#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  int sum = 0;
  rep(i, n) {
    cin >> p[i];
    p[i]++;
    if (i < k) sum += p[i];
  }
  int ans = sum;
  for (int i = k; i < n; i++) {
    sum += p[i];
    sum -= p[i - k];
    ans = max(ans, sum);
  }
  if (ans % 2) {
    cout << ans / 2 << ".5";
  } else {
    cout << ans / 2;
  }
  return 0;
}
