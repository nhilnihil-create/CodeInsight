#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define contains(v, t) (find(v.begin(), v.end(), t) != v.end())
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  long double sa, sb, sc, eps;
  sa = sqrtl(a);
  sb = sqrtl(b);
  sc = sqrtl(c);
  eps = 1.0E-14;
  if (sa + sb + eps < sc) {
    cout << "Yes";
  } else {
    cout << "No";
  }
}