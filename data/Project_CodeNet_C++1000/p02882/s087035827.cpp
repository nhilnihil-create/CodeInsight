#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  double a, b, x;
  cin >> a >> b >> x;
  double pi = acos(-1.0);
  double ans;
  if(2 * x > a * a * b)
    ans = atan2(2 * a * a * b - 2 * x, pow(a, 3)) * 180.0 / pi;
  else
    ans = atan2(a * b * b, 2 * x) * 180.0 / pi;
  printf("%.10f\n", ans);
}