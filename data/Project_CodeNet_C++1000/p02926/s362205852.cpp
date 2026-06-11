#include <bits/stdc++.h>
using namespace std;

using CP = complex<long double>;
#define X real()
#define Y imag()
const long double PI = acos(-1);
const long double EPS = 1e10;
// conj(x) : complex conjugate,(0,1)->(0,-1)
// abs(x) : dist between(0,0) and x
// norm(x) : abs(x) * abs(x)
// arg(x) : argment
long double dot(CP a, CP b) { return (a * conj(b)).X; }
long double cross(CP a, CP b) { return (a * conj(b)).Y; }

CP intersection(CP a, CP b, CP c, CP d) {
  return a + (b - a) * (cross(d - c, c - a) /
                        cross(d - c, b - a));
}

bool on_seg(CP a, CP b, CP p) {
  // if not use end point, dot(a - p, b - p) < 0
  return abs(cross(a - p, b - p)) <= 1e-10 &&
         dot(a - p, b - p) <= 0;
}

// crossing lines? (a,b) and (c,d)
bool iscross(CP a, CP b, CP c, CP d) {
  // parallel
  if(abs(cross(a - b, c - d)) <= 1e-10) {
    return on_seg(a, b, c) || on_seg(a, b, d) ||
           on_seg(c, d, a) || on_seg(c, d, b);
  }
  CP isp = intersection(a, b, c, d);
  return on_seg(a, b, isp) && on_seg(c, d, isp);
}

struct convex_hull {
  vector<CP> ch;
  int psize;
  convex_hull() {}
  convex_hull(vector<CP> &ps) { calculation(ps); }
  void calculation(vector<CP> &ps) {
    auto lmd = [&](const CP &l, const CP &r) {
      if(l.X != r.X) return l.X < r.X;
      return l.Y < r.Y;
    };
    psize = ps.size();
    sort(ps.begin(), ps.end(), lmd);
    int k = 0;
    ch.resize(psize * 2);
    for(int i = 0; i < psize; ++i) {
      while(k > 1 && cross(ch[k - 1] - ch[k - 2],
                           ps[i] - ch[k - 1]) <= 0)
        --k;
      ch[k++] = ps[i];
    }
    for(int i = psize - 2, t = k; i >= 0; --i) {
      while(k > t && cross(ch[k - 1] - ch[k - 2],
                           ps[i] - ch[k - 1]) <= 0)
        --k;
      ch[k++] = ps[i];
    }
    ch.resize(k - 1);
    psize = ch.size();
  }
};

long long n;
vector<CP> v;
convex_hull now;

long double solve();

int main() {
  cin >> n;
  for(int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    v.push_back(CP(x, y));
  }
  cout << fixed << setprecision(12);
  cout << solve() << endl;
  return 0;
}

long double solve() {
  now.ch.push_back(CP(0, 0));
  now.psize = 1;
  for(int i = 0; i < n; ++i) {
    vector<CP> tmp;
    for(int j = 0; j < now.psize; ++j) {
      CP nextp = now.ch[j];
      tmp.push_back(nextp);
      tmp.push_back(nextp + v[i]);
    }
    now = convex_hull(tmp);
  }
  long double ans = 0.0;
  for(int i = 0; i < now.psize; ++i)
    ans = max(ans, abs(now.ch[i]));
  return ans;
}