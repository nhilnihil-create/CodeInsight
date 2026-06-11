#include <bits/stdc++.h>
using namespace std;
#define rep(i, s, e) for (int i = s; i < e; ++i)
#define sort_(a) stable_sort(a.begin(), a.end())
#define rsort(a) stable_sort(a.rbegin(), a.rend())
#define sum(a) accumulate(a.begin(), a.end(), 0LL)
#define join(a, d) accumulate(a.begin() + 1, a.end(), a[0], [](string s, string t) {return s + d + t;})
#define all(a) a.begin(), a.end()
// #define __lcm(a, b) std::__detail::__lcm(a, b)
#define PI 3.141592653589793
#define degrees(a) a * 180.0 / PI;

typedef long long ll;
const long mod = 1e9 + 7;

int main(void) {
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
#endif

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  double A, B, X;
  cin >> A >> B >> X;
  double s1 = X / (A * A) * A;
  double h1 = (2 * s1) / B;
  double ans1 = degrees(atan2(B, h1));

  double s2 = A * B - s1;
  double h2 = (2 * s2) / A;
  double ans2 = degrees(atan2(h2, A));

  if (X / (A * A) <= B / 2)
    cout << fixed << setprecision(10) << ans1 << endl;
  else
    cout << fixed << setprecision(10) << ans2 << endl;
  return 0;
}
