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
  int n;
  cin >> n;
  ll ans = 0;
  FOR(i, 1, n) {
    if (i % 3 != 0 && i % 5 != 0) {
      ans += i;
    }
  }
  COUT(ans);

  return 0;
}
