#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N, M;
  cin >> N >> M;
  vector<ll> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    a[i] /= 2;
  }

  ll tmp = 1;
  for (int i = 0; i < N; i++) {
    tmp = tmp * a[i] / __gcd(tmp, a[i]);
  }
  for (int i = 0; i < N; i++) {
    if (tmp / a[i] % 2 == 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  cout << (tmp <= M) + (M - tmp) / (2 * tmp) << endl;
}