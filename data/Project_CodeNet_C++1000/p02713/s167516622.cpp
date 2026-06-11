#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = a; i < (b + a); i++)
#define W1 while (1)
#define COUT(x) cout << x << endl
using namespace std;
using ll = long long;
using ld = long double;
#define ALL(x) x.begin(),x.end()
#define P pair<int,int>
#define mod 1000000007
#define PB push_back
#define F first
#define S second

int main() {
  int k;
  cin >> k;
  ll ans = 0;
  FOR(i, 1, k) {
    FOR(j, 1, k) {
      int ij = __gcd(i, j);
      FOR(l, 1, k) {
        ans += __gcd(ij, l);
      }
    }
  }
  COUT(ans);

  return 0;
}
