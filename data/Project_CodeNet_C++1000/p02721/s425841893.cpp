#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
#define INF (1e9)

int main() {
  ll N;
  cin >> N;
  ll K;
  cin >> K;
  ll C;
  cin >> C;
  string S;
  cin >> S;

  vi l(N + 1), r(N + 1);
  for (ll i = 0; i < N; i++) {
    l[i + 1] = l[i];
    if (S[i] == 'o') {
      if (i > C)
        l[i + 1] = max(l[i + 1], l[i - C] + 1);
      else
        l[i + 1] = 1;
    }
  }
  for (ll i = N - 1; i >= 0; i--) {
    r[i] = r[i + 1];
    if (S[i] == 'o') {
      if (i < N - C)
        r[i] = max(r[i], r[i + C + 1] + 1);
      else
        r[i] = 1;
    }
  }

  for (ll i = 0; i < N; i++) {
    if (l[i] + r[i + 1] < K) {
      cout << i + 1 << endl;
    }
  }
}
