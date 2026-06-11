#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) {
    cin >> a[i];
    --a[i];
  }

  vector<int> cnt(n, 0);
  rep(i, n) ++cnt[a[i]];

  ll sum_comb = 0;
  rep(i, n) {
    sum_comb += (ll)cnt[i] * (cnt[i] - 1) / 2;
  }

  vector<ll> comb_i(n);
  rep(i, n) comb_i[i] = sum_comb - cnt[a[i]] + 1;
  rep(i, n) cout << comb_i[i] << endl;
  return 0;
}