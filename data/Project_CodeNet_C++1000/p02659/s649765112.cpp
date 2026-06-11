#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  ll a;
  double b;
  cin >> a >> b;
  double ib = b * 100;
  ll ans = a * (ll)(ib + 0.5) / 100;
  cout << ans << endl;
  return 0;
}