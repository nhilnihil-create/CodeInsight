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

  ll sum = accumulate(va.begin(), va.end(), 0ll);
  vector<ll> divs;
  for (ll i = 1; i * i <= sum; ++i) {
    if (sum % i == 0) {
      divs.push_back(i);
      divs.push_back(sum / i);
    }
  }

  sort(divs.begin(), divs.end(), greater<ll>());

  ll ans = -1;
  for (auto d : divs) {
    vector<ll> vb;
    transform(va.begin(), va.end(), back_inserter(vb),
              [&](ll a) { return a % d; });
    sort(vb.begin(), vb.end());

    vector<ll> psum1(va.size() + 1, 0), psum2(va.size() + 1, 0);
    for (int i = 1; i < psum1.size(); ++i) {
      psum1[i] = psum1[i - 1] + vb[i - 1];
      psum2[i] = psum2[i - 1] + (d - vb[i - 1]);
    }

    bool ok = false;
    int cnt;
    for (int j = 0; j < psum1.size(); ++j) {
      if (psum1[j] == psum2.back() - psum2[j]) {
        ok = true;
        cnt = psum1[j];
        break;
      }
    }

    if (ok && cnt <= k) {
      ans = d;
      break;
    }
  }

  cout << ans << '\n';
}