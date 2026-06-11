#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define ll long long
#define mset(s, _) memset(s, _, sizeof s)
#define ALL(a) (a).begin(), (a).end()
using namespace std;

int main(void) {
  ll W, H;
  cin >> W >> H;
  ll x, y;
  cin >> x >> y;

  double area = W * H / 2.0;
  printf("%.10f", area);
  if (W / 2.0 == x && H / 2.0 == y) {
    cout << " 1";
  } else {
    cout << " 0";
  }
  cout << endl;
  return 0;
}
