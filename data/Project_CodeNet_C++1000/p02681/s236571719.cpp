#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
#define repi(n) for (int i = 0; i < (n); i++)
#define repj(n) for (int j = 0; j < (n); j++)
#define repk(n) for (int k = 0; k < (n); k++)
#define rep(i, a, b) for (auto i = (a); i < (b); i++)
#define itr(itr) for (auto&& v : (itr))
#define updatemax(t, v) (t = std::max(t, (v)))
#define updatemin(t, v) (t = std::min(t, (v)))

int main() {
  string s, t;
  cin >> s >> t;
  cout << (s == t.substr(0, s.length()) ? "Yes" : "No") << endl;
}
