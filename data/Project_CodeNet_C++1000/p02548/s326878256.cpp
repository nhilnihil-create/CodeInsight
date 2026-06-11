#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  int ans = 0;
  for (int i = 1; i<n; i++) {
    ans += n / i;
    if (n % i == 0) ans--;
  }
  cout << ans << endl;
  return 0;
}