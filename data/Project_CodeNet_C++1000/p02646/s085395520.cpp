#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll a, v, b, w;
  cin >> a >> v >> b >> w;
  ll t;
  cin >> t;
  if (abs(a-b)+w*t <= v*t) cout << "YES" << endl;
  else cout << "NO" << endl;
}