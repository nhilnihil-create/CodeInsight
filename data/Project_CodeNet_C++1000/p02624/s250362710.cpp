#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;

  vector<int> f(N + 1);
  for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j += i) {
      f[j]++;
    }
  }

  ll ans = 0;
  for (ll k = 1; k <= N; k++) {
    ans += k * f[k];
  }
  cout << ans << endl;
  return 0;
}