#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n,k;
  cin >> n >> k;

  int ans = 0;
  rep(i,n) {
    int a; cin >> a;
    if(a >= k) ans++;
  }
  cout << ans << '\n';
}
