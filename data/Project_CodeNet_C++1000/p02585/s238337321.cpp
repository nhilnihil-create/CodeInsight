#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  vector<int> p(n), a(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  long long ans = -5e18;
  vector<bool> visit;

  for (int i = 0; i < n; i++) {
    visit.assign(n, false);
    int v = i, len = 0;
    long long sum = 0;

    while (!visit[v]) {
      visit[v] = true;
      v = p[v];
      sum += a[v];
      len++;
    }
    
    int round = max(0, k / len - 1);
    int tail = k - round * len;
    long long best = -5e18, now = 0;

    while (tail--) {
      v = p[v];
      now += a[v];
      best = max(best, now);
    }
    if (sum > 0) best += round * sum;
    ans = max(ans, best);
  }
  
  cout << ans << '\n';

  return 0;
}
