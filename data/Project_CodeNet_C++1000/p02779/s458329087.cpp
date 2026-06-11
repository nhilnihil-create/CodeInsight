#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  int n;
  cin >> n;
  vector<ll> v(n);
  rep(i, n) cin >> v[i];
  sort(v.begin(), v.end());
  bool flag = true;
  rep(i, n - 1) {
    if (v[i] == v[i + 1]) {
      flag = false;
      break;
    }
  }
  if (flag)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}