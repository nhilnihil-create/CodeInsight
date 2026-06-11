#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int main() {
  ll N, K;
  cin >> N >> K;
  if (N == K) {
    cout << 0 << endl;
  } else if (K < N) {
    ll a = N / K;
    ll m = min(N - a * K, (a + 1) * K - N);
    cout << m << endl;
  } else {
    set<ll> s;
    ll a = K - N;
    s.insert(a);
    ll m = a;
    while (1) {
      a = abs(a - K);
      m = min(m, a);
      if (s.find(a) != s.end()) {
        break;
      }
    }
    cout << m << endl;
  }
  return 0;
}