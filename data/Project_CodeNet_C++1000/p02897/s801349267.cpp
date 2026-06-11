 #include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i<(n); ++i)

int main() {
  ll n; cin >> n;
  double a = (n/2+1.0)/n;
  if(n%2==0) cout << 0.5 << endl;
  else cout << a << endl;

  return 0;
}