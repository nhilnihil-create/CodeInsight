#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
  int N;
  cin >> N;

  vector<int> A(N + 1);
  vector<int> B(N);
  rep(i, A.size()) {
    cin >> A[i];
  }
  rep(i, B.size()) {
    cin >> B[i];
  }

  ll ans = 0;

  rep(i, N) {
    int defeat = min(B[i], A[i]);
    ans += defeat;
    B[i] -= defeat;
    defeat = min(B[i], A[i + 1]);
    ans += defeat;
    A[i + 1] -= defeat;
  }

  cout << ans << endl;

  return 0;
}