#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  rep(i, n) cin >> A.at(i);
  sort(A.rbegin(), A.rend());

  ll ans = 0;
  rep(i, n) {
    if (i == 1) {
      ans += A.at(0);
    } else if (i != 0) {
      ans += A.at(i / 2);
    }
  }

  cout << ans << endl;
  return 0;
}