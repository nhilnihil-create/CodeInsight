#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1000000000;

int main() {
  ll s, v = 1000000000;
  cin >> s;

  ll x = (v - s % v) % v;
  ll y = (s + x) / v;

  cout << "0 0 1000000000 1 " << x << " " << y << endl;
  return 0;
}
