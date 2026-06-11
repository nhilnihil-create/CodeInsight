#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  vector<int> A(N);
  rep(i, N) cin >> A[i];

  ll ans = 0;
  int maxh = 0;
  rep(i, N) {
    maxh = max(maxh, A[i]);
    ans += maxh - A[i];
  }
  cout << ans << endl;
  return 0;
}