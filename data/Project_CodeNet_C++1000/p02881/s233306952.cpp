#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  ll n;
  cin >> n;
  ll ans = 1e18;
  for(ll i=1; i*i<=n; i++) {
    if(n%i != 0) continue;
    ans = min(i+n/i-2, ans);
  }
  cout << ans << endl;
  return 0;
}