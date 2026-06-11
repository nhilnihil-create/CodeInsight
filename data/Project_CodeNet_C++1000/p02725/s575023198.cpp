#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
  int k, n;
  cin >> k >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int m = 0;
  rep(i, n - 1) m = max(m, a[i + 1] - a[i]);
  m = max(m, a[0] + k - a[n - 1]);
  cout << k - m;
}
