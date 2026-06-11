#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

int main() {
  ll n, sum = 0;
  cin >> n;
  for (ll i = 1; i <= n; i++) {
    if (i % 3 == 0 || i % 5 == 0) continue;
    sum += i;
  }
  cout << sum << endl;
}
