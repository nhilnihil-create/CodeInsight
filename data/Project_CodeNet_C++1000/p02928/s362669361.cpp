#include <bits/stdc++.h>

using namespace std;

using ll = long long;
const ll MOD = 1000000007;

ll solve() {
  ll N, K;
  cin >> N >> K;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
  }

  ll ans = 0;

  ll combi = ((K * (K - 1)) / 2) % MOD;

  for (ll i = 0; i < N; i++) {
    ll CL = 0;
    ll CR = 0;

    for (ll j = 0; j < N; j++) {
      if (A[j] < A[i]) {
        if (j < i) {
          CL++;
        } else {
          CR++;
        }
      }
    }

    ans += (K * CR) % MOD + (combi * (CL + CR)) % MOD;
    ans = ans % MOD;
  }
  return ans % MOD;
}

int main() {
  cout << solve() << endl;
  return 0;
}
