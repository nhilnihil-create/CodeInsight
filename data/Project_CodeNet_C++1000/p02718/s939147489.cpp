#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int n,m;
  cin >> n >> m;
  int sum = 0;
  vector<int> a(n);
  rep(i,n) {
    cin >> a[i];
    sum += a[i];
  }
  int ans = 0;
  rep(i,n) {
    if (4 * m * a[i] >= sum) {
      ans += 1;
    }
  }
  if (ans >= m) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
