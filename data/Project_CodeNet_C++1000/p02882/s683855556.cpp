#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) (x).begin, (x).end
#define sz(x) (int)(x).size()
#define rep1(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); i++)
#define get4(_1, _2, _3, _4, ...) _4
#define rep(...) get4(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long double a, b, x;
  cin >> a >> b >> x;
  long double h = x / (a * a);
  long double ans;
  if (h >= (b / 2)) {
    ans = atan(2 * (b - h) / a) * 180 / M_PI;
  } else {
    ans = atan(b / (2 * x / (a * b))) * 180 / M_PI;
  }
  cout << fixed << setprecision(15) << ans << '\n';
  return 0;
}
