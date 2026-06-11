#include <bits/stdc++.h>

using namespace std;

int get(int n) {
  int cnt = 0;
  while (n > 1) {
    cnt += n /= 2;
  }
  return cnt;
}

bool par(int n, int k) {
  return get(n) > get(k) + get(n - k);
}

int solve(vector<int> a) {
  for (int& x : a) {
    x &= 1;
  }
  int n = a.size();
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (!par(n - 1, i)) {
      ans ^= a[i];
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  bool one = false;
  for (int& x : a) {
    char c;
    cin >> c;
    x = c - '1';
    one |= x == 1;
  }
  auto res = solve(a);
  if (res == 1) {
    cout << res;
  } else if (one) {
    cout << 0;
  } else {
    for (int &x : a) {
      x /= 2;
    }
    cout << solve(a) * 2;
  }

  return 0;
}