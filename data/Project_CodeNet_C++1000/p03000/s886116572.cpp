#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int n,x;
  cin >> n >> x;
  std::vector<int> d(n+1);
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    d[i+1] = d[i] + x;
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    if (d[i] <= x) {
      ans++;
    }
  }
  cout << ans << endl;
}
