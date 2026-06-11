#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  vector<int> x(5);
  int ans;
  rep(i, 5) {
    cin >> x[i];
    if (x[i] == 0) {
      ans = i+1;
    }
  }

  cout << ans << endl;
  return 0;
}