#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int W, H, x, y;
  cin >> W >> H >> x >> y;
  double w = W, h = H;

  cout << fixed << setprecision(10) << (w * h) / 2 << " ";
  if (W == x + x && H == y + y)
    cout << 1 << endl;
  else
    cout << 0 << endl;
}
