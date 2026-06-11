#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll N, K; cin >> N >> K;
  vector<ll> A(N), F(N);

  for (ll i = 0; i < N; i++) cin >> A[i];
  for (ll i = 0; i < N; i++) cin >> F[i];

  sort(A.begin(), A.end());
  sort(F.begin(), F.end(), greater<ll>());

  ll left = 0, right = static_cast<ll>(10e12);

  while (left < right) {
    ll mid = (left + right) / 2;

    ll x = K;
    ll ok = true;
    for (ll i = 0; i < N && ok; i++) {
      if (mid < A[i] * F[i]) {
        ll d = A[i] - mid / F[i];

        if (d <= x) {
          x -= d;
        } else {
          ok = false;
        }
      }
    }

    if (ok) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  cout << left << endl;
}
