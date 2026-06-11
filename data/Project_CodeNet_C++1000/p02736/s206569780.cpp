#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
//const int mod = ;

int f(vi a) {
  int n = a.size() - 1;
  int res = 0;
  for (int i = 0; i < a.size(); ++i) {
    if ((i & n) == i) res += a[i];
  }
  return res % 2;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  vi a(n);
  for (int i = 0; i < n; ++i) a[i] = s[i] - '0';
  vi b(n-1);
  int c1 = 0;
  for (int i = 0; i + 1 < n; ++i) {
    b[i] = abs(a[i] - a[i + 1]);
    c1 += b[i] == 1;
  }
  --n;
  if (c1 == 0) {
    for (int i = 0; i < b.size(); ++i) b[i] /= 2;
    cout << f(b) * 2 << endl;
  } else {
    for (int i = 0; i < b.size(); ++i) b[i] %= 2;
    cout << f(b) << endl;
  }
  return 0;
}
