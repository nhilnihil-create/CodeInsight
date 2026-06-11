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
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  while (1) {
    c -= b;
    if (c <= 0) break;
    a -= d;
    if (a <= 0) break;
  }
  cout << ((a <= 0) ? "No" : "Yes") << endl;
}
