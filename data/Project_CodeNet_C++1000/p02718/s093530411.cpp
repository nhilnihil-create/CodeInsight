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
  int n, m, sum = 0, res = 0;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n) {
    cin >> a[i];
    sum += a[i];
  }
  rep(i, n) if ((double)a[i] >= (double)sum / (4 * m)) res++;
  cout << ((res >= m) ? "Yes" : "No") << endl;
}
