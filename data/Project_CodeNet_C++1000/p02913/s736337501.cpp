#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MOD = 1e9 + 7;
int n;
string s;

bool double_check(int i1, int i2, int k) {
  while (k) {
    if (s[i1--] != s[i2--]) return false;
    --k;
  }
  return true;
}

bool check(int k) {
  // cout << "check: " << k << endl;
  ll sum = 0;
  ll base = 1;
  unordered_map<ll, int> mp;
  for (int i = 0; i < k; ++i) {
    sum = (sum * 26 + (s[i] - 'a')) % MOD;
    base = base * 26 % MOD; // next base
  }
  mp[sum] = k - 1;
  for (int i = k; i < n; ++i) {
    sum = (sum * 26 % MOD + (s[i] - 'a')) % MOD;
    sum = (sum - (base * (s[i - k] - 'a') % MOD)) % MOD;
    if (sum < 0) sum += MOD;
    // cout << i - k + 1 << ' ' << sum << endl;
    if (mp.count(sum)) {
      int right = mp[sum];
      if (i - k + 1 > right) {
        if (double_check(right, i, k))
          return true;
      }
    } else {
      mp[sum] = i;
    }
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> s;
  int l = 1;
  int r = n / 2;
  while (l < r) {
    int m = (l + r + 1) / 2;
    if (check(m)) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  if (check(l)) {
    cout << l << endl;
  } else {
    cout << 0 << endl;
  }


  return 0;
}
