#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;

  ll ans = 0;
  for (int i = 1; i <= N; i++) {
    ll k = N / i;
    ans += i * (k * (k + 1) / 2);
  }
  cout << ans << endl;
  return 0;
}