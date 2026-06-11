#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  //cout << "aaa" << endl;
  while (true) {
    ll n, k;
    cin >> n >> k;
    if (n == 0 && k == 0) break;
    vector<ll> A(n);
    for (ll i = 0; i < n; i++) {
      cin >> A[i];
    }

    vector<ll> s(n);
    for (ll i = 0; i < n; i++) {
      s[i + 1] = s[i] + A[i];
    }
    ll mx = (1LL << 60) * -1;

    for (ll i = 0; i < n - k; i++) {
      mx = max(mx, s[i + k] - s[i]);
    }
    cout << mx << endl;
  }
}
