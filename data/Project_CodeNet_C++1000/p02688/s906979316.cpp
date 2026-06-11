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
  ll n, k, d, i, j, a_tmp, cnt = 0;
  cin >> n >> k;
  vector<ll> a(n, false);
  rep(i, k) {
    cin >> d;
    rep(j, d) {
      cin >> a_tmp;
      a[a_tmp - 1] = true;
    }
  }
  rep(i, n) if (a[i] == false) cnt++;
  cout << cnt << endl;
}
