#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> P;

const long double EPS = 1e-10;
const long long INF = 1e18;
const int MOD = (int)1e9 + 7;
const long double PI = acos(-1.0L);

int main() {  // TODO
  ll W, H, x, y;
  cin >> W >> H >> x >> y;

  cout << fixed << setprecision(20) << (double)W * H / 2.0;

  if (W == x * 2 && H == y * 2) {
    cout << " " << 1 << endl;
  } else {
    cout << " " << 0 << endl;
  }

  return 0;
}