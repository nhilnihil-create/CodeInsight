#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<ll> cnt(n, 0);
  rep(i, n) {
    cin >> a[i];
    a[i]--;
    cnt[a[i]]++;
  }
  ll sum = 0;
  rep(i, n) {
    sum += cnt[i] * (cnt[i] - 1) / 2;
  }
  vector<ll> ans(n, sum);
  rep(i, n) {
    ans[i] -= cnt[a[i]] * (cnt[a[i]] - 1) / 2;
    ans[i] += (cnt[a[i]] - 1) * (cnt[a[i]] - 2) / 2;
    cout << ans[i] << '\n';
  }
  return 0;
}
