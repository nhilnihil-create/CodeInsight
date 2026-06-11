#include<bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, d, a;
  cin >> n >> d >> a;
  vector<pair<long long, long long>> xh(n);
  for (int i = 0; i < n; i++) {
    cin >> xh[i].first >> xh[i].second;
  }
  sort(xh.begin(), xh.end());
  int cur = 1;
  vector<long long> cnt(n);
  for (int i = 0; i < n; i++) {
    cnt[i] = (long long) ceil((double) xh[i].second / a);
  }
  vector<long long> cnt2(n, 0);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    while (cur < n && xh[cur].first <= xh[i].first + 2 * d) {
      cur++;
    }
    long long t = max(0LL, cnt[i] - cnt2[i]);
    ans += t;
    cnt2[i] += t;
    if (i == n - 1) break;
    cnt2[cur] -= t;
    cnt2[i + 1] += cnt2[i];
  }
  cout << ans << '\n';
  return 0;
}

