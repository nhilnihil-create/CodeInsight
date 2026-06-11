#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int sum = 0;
  rep(i, n) sum ^= a[i];
  cout << (sum == 0 ? "Yes" : "No") << endl;
  return 0;
}
