#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll x = 1e9 + 7; 
const int INF = 1001001001;


int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  ll ans = a*(n/(a+b));
  ans += min(n%(a+b), a);
  cout << ans << endl;
  return 0;
}