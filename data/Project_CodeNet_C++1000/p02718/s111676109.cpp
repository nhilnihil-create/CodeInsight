#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m;
  double total = 0;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) {
    cin >> a[i];
    total += a[i];
  }
  sort(a.rbegin(), a.rend());
  cout << (a[m - 1] >= total / 4 / m ? "Yes" : "No") << endl;
  return 0;
}
