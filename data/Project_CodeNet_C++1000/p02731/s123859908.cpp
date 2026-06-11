#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define ll long long
#define mset(s, _) memset(s, _, sizeof s)
#define ALL(a) (a).begin(), (a).end()
using namespace std;

int main(void) {
  int L;
  cin >> L;

  double x = L / 3.0;
  double y = L / 3.0;
  double z = L / 3.0;

  printf("%.10lf", x * y * z);
  return 0;
}
