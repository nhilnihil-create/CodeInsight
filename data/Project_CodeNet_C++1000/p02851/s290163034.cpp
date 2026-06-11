#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(int argc, const char *argv[]) {
  ll n, k;
  cin >> n >> k;
  vector<ll> va(n);
  for (int i = 0; i < n; ++i) {
    cin >> va[i];
  }

  vector<ll> psum{0};
  partial_sum(va.begin(), va.end(), back_inserter(psum));
  transform(psum.begin(), psum.end(), psum.begin(),
            [&](ll a) { return a % k; });

  map<int, int> cnt;
  ll ans = 0;
  auto msub = [](int a, int b, int md) { return ((a - b) % md + md) % md; };
  for (int i = 0; i < psum.size(); ++i) {
    int x = msub(psum[i], i, k);
    ans += cnt[x];
    cnt[x]++;
    if (i - k + 1 >= 0) {
      int y = msub(psum[i - k + 1], i - k + 1, k);
      cnt[y]--;
    }
  }

  cout << ans << '\n';
}