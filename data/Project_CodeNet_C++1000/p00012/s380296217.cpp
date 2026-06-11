#include<iostream>
#include<complex>
#include<vector>
#include<cmath>
#include<algorithm>
#include<cstdio>

using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)

#define X real()
#define Y imag()

typedef long double D;
typedef complex<D> P;
typedef pair<P, P> L;
typedef vector<P> Pol;

const D INF = 1e40;
const D EPS = 1e-8;
const D PI = acos(-1);

int sig(D r) {return (r < -EPS) ? -1 : (r > EPS) ? 1: 0;}
bool eq(D a, D b) {return abs(a - b) < EPS;}
bool near(P a, P b) {return abs(b - a) < EPS;}

// 内積
D dot(P a, P b) {return a.X * b.X + a.Y * b.Y;}
// 外積
D cross(P a, P b) {return a.X * b.Y - a.Y * b.X;}

// 線分のベクトル
P vec(L a) {return a.second - a.first;}

// 線分abに対する点xの位置
enum CCW{FRONT = 1, RIGHT = 2, BACK = 4, LEFT = 8, ON = 16};
int ccw(L s, P p) {
  P a = vec(s);
  p -= s.first;
  D cr = cross(a, p);
  if (eq(cr, 0)) {
    if (sig(dot(a, p)) < 0) return BACK;
    if (sig(norm(a) - norm(p)) < 0) return FRONT;
    return ON;
  }
  return (cr > 0) ? LEFT : RIGHT;
}

int main() {
  P a, b, c, p;
  while (cin >> a.X >> a.Y >> b.X >> b.Y >> c.X >> c.Y >> p.X >> p.Y) {
    int bit = ccw(L(a, b), p) | ccw(L(b, c), p) | ccw(L(c, a), p);
    if (bit == LEFT || bit == RIGHT) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}