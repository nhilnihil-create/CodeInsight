#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;
using ll = long long;

int main() {
  ll N, A, B;
  cin >> N >> A >> B;

  ll d = abs(A-B);
  ll ans = 0;
  if (d % 2 == 0) ans = d / 2;
  else {
    if (A - 1 < N - B) {
      ans += A - 1;
      B = B - A + 1;
      A = 1;
    } else {
      ans += N - B;
      A += N - B;
      B = N;
    }

    d = abs(A-B);
    if (d % 2 == 0) ans += d / 2;
    else ans += d / 2 + 1;
  }

  cout << ans << endl;
  return 0;
}
