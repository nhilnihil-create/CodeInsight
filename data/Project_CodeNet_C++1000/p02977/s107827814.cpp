#include <bits/stdc++.h>
using namespace std;

unsigned long long popcount(unsigned long long x) {
  x = ((x & 0xaaaaaaaaaaaaaaaaUL) >> 1) + (x & 0x5555555555555555UL);
  x = ((x & 0xccccccccccccccccUL) >> 2) + (x & 0x3333333333333333UL);
  x = ((x & 0xf0f0f0f0f0f0f0f0UL) >> 4) + (x & 0x0f0f0f0f0f0f0f0fUL);
  x = ((x & 0xff00ff00ff00ff00UL) >> 8) + (x & 0x00ff00ff00ff00ffUL);
  x = ((x & 0xffff0000ffff0000UL) >> 16) + (x & 0x0000ffff0000ffffUL);
  x = ((x & 0xffffffff00000000UL) >> 32) + (x & 0x00000000ffffffffUL);
  return x;
}

using P = pair<int, int>;

int n;
vector<P> res;

bool solve();

int main() {
  cin >> n;
  if (solve()) {
    cout << "Yes" << endl;
    for (auto p : res) cout << p.first << " " << p.second << endl;
  } else
    cout << "No" << endl;
  return 0;
}

bool solve() {
  int len = (n + 1) / 4 * 4, id = -1;
  if (n < 3 || (n % 4 == 0 && popcount(len) == 1)) return 0;
  vector<int> v(1, len - 1);
  for (int i = len - 2, now = 0; i >= 1; --i) {
    if (now < 0 && i != 1 && i != 3)
      v.push_back(i);
    else if (now >= 0) {
      now ^= i;
      v.push_back(i);
      if (now == len) {
        id = i;
        now = -1;
        v.push_back(1);
        v.push_back(3);
      }
    }
  }
  for (int i = 1; i < len - 1; ++i) res.emplace_back(v[i - 1], v[i]);
  res.emplace_back(v[len - 2], v[0] + n);
  for (int i = 1; i < len - 1; ++i) res.emplace_back(v[i - 1] + n, v[i] + n);
  if (popcount(len) == 1) {
    if (n % 4 == 1) {
      res.emplace_back(n - 1, n);
      res.emplace_back(2 * n - 1, 2 * n);
      res.emplace_back(1, n - 1);
      res.emplace_back(n + 1, 2 * n);
    }
    if (n % 4 == 2) {
      res.emplace_back(2, len + n);
      res.emplace_back(2 + n, len + 2);
      res.emplace_back(len + 2, len);
      res.emplace_back(len + 2, len + 1);
      res.emplace_back(1 + n, len + 1 + n);
      res.emplace_back(len + 1 + n, len + 2 + n);
    }
  } else {
    if ((n + 1) % 4 > 0) {
      res.emplace_back(len - 2, len);
      res.emplace_back(id, len + n);
    }
    if ((n + 1) % 4 > 1) {
      res.emplace_back(len - 2, len + 1);
      res.emplace_back(1, len + 1 + n);
    }
    if ((n + 1) % 4 > 2) {
      res.emplace_back(len - 2, len + 2);
      res.emplace_back(3, len + 2 + n);
    }
  }
  return 1;
}