
// Problem: A - Takahashikun, The Strider
// Contest: AtCoder - AtCoder Grand Contest 046
// URL: https://atcoder.jp/contests/agc046/tasks/agc046_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e6 + 1;

int x;

int32_t main() { cin.tie(0)->sync_with_stdio(0);
  cin >> x;
  cout << 360 / __gcd(x, 360);
}