#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  ll n, k, ans = 0;
  cin >> n >> k;

  cout << (k == 1 ? 0 : n - k) << endl;
  return 0;
}
