#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define mins(x, y) (x = min(x, y))
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main(void) {
  int n, k, q, input;
  cin >> n >> k >> q;
  vector<int> a(n, k - q);
  rep(i, q) {
    cin >> input;
    a[input - 1]++;
  }
  rep(i, n) {
    if (a[i] > 0)
      cout << "Yes" << '\n';
    else
      cout << "No" << '\n';
  }
  return 0;
}