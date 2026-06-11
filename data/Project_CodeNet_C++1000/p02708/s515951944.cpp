#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll m = 1000000007;

int main() {
  ll n, k;
  cin >> n >> k;

  ll cnt = 0;
  for (ll i = k; i <= n + 1; i++) {
    cnt += i * (n - i + 1) + 1;
    cnt %= m;
  }
  cout << cnt << endl;
}
