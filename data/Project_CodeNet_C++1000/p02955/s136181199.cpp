#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

bool solve(int k, ll d, vector<ll> &a) {
  int n = a.size();
  vector<ll> b(n);
  for (int i = 0; i < n; i++) {
    b[i] = a[i] % d;
  }
  sort(b.begin(), b.end());
  int i = 0, j = n - 1;
  // ソート済みのやつの両端から足し引き
  // 降順なので、初めは減らしたい、後は増やしたい
  ll now = 0;
  // 現在の増減量
  ll num = 0;
  // 操作回数
  while (i <= j) {
    if (now <= 0) {
      now += b[i];
      num += b[i];
      i++;
    } else {
      now -= (d - b[j]);
      j--;
    }
  }
  return num <= k;
}

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  ll ans = 0;
  for (ll i = 1; i * i <= sum; i++) {
    if (sum % i == 0) {
      if (solve(k, i, a)) {
        ans = max(ans, i);
      }
      if (solve(k, sum / i, a)) {
        ans = max(ans, sum / i);
      }
    }
  }
  cout << ans << endl;
}
