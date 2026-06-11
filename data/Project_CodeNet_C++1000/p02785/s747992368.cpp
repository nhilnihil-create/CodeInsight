#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> hp(n);
  rep(i, n) cin >> hp[i];
  sort(hp.begin(), hp.end());
  if (hp.size() <= k) {
    cout << 0 << endl;
  } else {
    ll attack_times = 0;
    rep(i, n - k) attack_times += hp[i];
    cout << attack_times << endl;
  }
  return 0;
}