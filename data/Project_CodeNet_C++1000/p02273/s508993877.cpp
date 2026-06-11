#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define rep(i, n)    FOR(i, 0, n)
#define pb           push_back
#define all(a)       (a).begin(), (a).end()
#define UNIQUE(v)    v.erase(unique(all(v)), v.end());
#define fill(a, x)   memset(a, x, sizeof(a))
#define zero(a)      fill(a, 0)
#define minus(a)     fill(a, -1)
#define dbg(x)       cout << #x "=" << x << endl

struct Point {
  double x;
  double y;
};

// Stackで実装してみるのも良さそう
void koch(int n, Point a, Point b) {
  if (n == 0) {
    return;
  }

  Point s, t, u;
  double th = M_PI * 60.0 / 180.0;

  s.x = (2.0 * a.x + 1.0 * b.x) / 3.0;
  s.y = (2.0 * a.y + 1.0 * b.y) / 3.0;
  t.x = (1.0 * a.x + 2.0 * b.x) / 3.0;
  t.y = (1.0 * a.y + 2.0 * b.y) / 3.0;
  u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
  u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;
  koch(n - 1, a, s);
  printf("%.8f %.8f\n", s.x, s.y);
  koch(n - 1, s, u);
  printf("%.8f %.8f\n", u.x, u.y);
  koch(n - 1, u, t);
  printf("%.8f %.8f\n", t.x, t.y);
  koch(n - 1, t, b);
}

int main() {
  // ios::sync_with_stdio(false);

  int n;
  cin >> n;

  Point ss = {0.00000000, 0.00000000};
  Point ll = {100.00000000, 0.00000000};

  printf("%.8f %.8f\n", ss.x, ss.y);
  koch(n, ss, ll);
  printf("%.8f %.8f\n", ll.x, ll.y);

  return 0;
}

