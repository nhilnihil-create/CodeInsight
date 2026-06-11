#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, a, b; cin >> n >> a >> b;
  ll x = n / (a+b);
  ll y = n % (a+b);
  cout << a*x + min(a, y) << endl;
  return 0;
}