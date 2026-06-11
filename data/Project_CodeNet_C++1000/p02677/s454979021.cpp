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

int main() {
  double a, b, h, m;
  cin >> a >> b >> h >> m;
  double th = ((60 * h) + m) / 720 * 360;
  double tm = m / 60 * 360;
  cout << fixed << setprecision(20);
  double t = abs(th - tm);
  if (t > 180.0) {
    t = 360 - t;
  }
  cout << sqrt((a * a) + (b * b) - (2 * a * b * cos(PI / 180 * t))) << endl;
  return 0;
}