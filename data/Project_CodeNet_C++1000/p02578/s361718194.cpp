#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
using namespace std;
using ll = long long;
using vi = vector<int>;

int main() {
  int N;
  cin >> N;
  vi A(N);
  rep(i, N) cin >> A[i];
  ll ans = 0;
  int prev = A[0];
  rep(i, N - 1) {
    if (A[i + 1] < prev) {
      ans += prev - A[i + 1];
    } else {
      prev = A[i + 1];
    }
  }

  cout << ans << endl;
  return 0;
}
