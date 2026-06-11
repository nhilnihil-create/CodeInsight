#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  cout << min(min(a+b, b+c), min(b+c, c+a)) << endl;
}