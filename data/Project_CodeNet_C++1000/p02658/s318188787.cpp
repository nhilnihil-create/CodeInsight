#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MAX 1000000000000000000
using namespace std;
using ll = long long int;

int main() {
  int N;
  cin >> N;

  bool has_zero = false;
  vector<ll> A(N, 0);
  rep(i, N) {
    cin >> A[i];
    if (A[i] == 0) has_zero = true;
  }

  if (has_zero) {
    cout << 0 << endl;
    return 0;
  }

  ll ans = 1;
  rep(i, N) {
    if (A[i] > MAX / ans) {
      cout << -1 << endl;
      return 0;
    }
    ans *= A[i];
  }

  cout << ans << endl;
}