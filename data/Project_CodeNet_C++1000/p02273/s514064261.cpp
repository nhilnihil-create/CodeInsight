#include <bits/stdc++.h>

using namespace std;

#define FOR(i,s,e) for((i)=(s);(i)<(int)(e);(i)++)
#define REP(i,e) FOR(i,0,e)

#define all(o) (o).begin(), (o).end()
#define psb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))

typedef long long ll;
typedef pair<int, int> PII;

const double EPS = 1e-10;

typedef struct point_def {
  double x;
  double y;

  point_def(double _x, double _y) {
    x = _x;
    y = _y;
  }

} p;

void koch(int d, p pl, p pr) {

//pl__s//u\\t__pr

  if (!d) return;

  p ps(0, 0), pt(0, 0), pu(0, 0);
  ps.x = (pl.x * 2 + pr.x)/3;
  ps.y = (pl.y * 2 + pr.y)/3;
  pt.x = (pl.x + pr.x * 2)/3;
  pt.y = (pl.y + pr.y * 2)/3;
  pu.x = ps.x + (pt.x-ps.x)*0.5 - (pt.y-ps.y)*sqrt(3.0)*0.5;
  pu.y = ps.y + (pt.x-ps.x)*sqrt(3.0)*0.5 + (pt.y-ps.y)*0.5;

  koch(d-1, pl, ps); printf("%.8f %.8f\n", ps.x, ps.y);
  koch(d-1, ps, pu); printf("%.8f %.8f\n", pu.x, pu.y);
  koch(d-1, pu, pt); printf("%.8f %.8f\n", pt.x, pt.y);
  koch(d-1, pt, pr);
}

int main() {
  int n;
  p pl = p(0.0, 0.0);
  p pr = p(100.0, 0.0);
  scanf("%d ", &n);
  printf("%.8f %.8f\n", pl.x, pl.y);
  koch(n, pl, pr);
  printf("%.8f %.8f\n", pr.x, pr.y);
  return 0;
}