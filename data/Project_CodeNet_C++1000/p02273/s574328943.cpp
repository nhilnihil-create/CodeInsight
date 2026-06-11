#include <bits/stdc++.h>
using namespace std;

struct Point {
  double x, y;
};

int N;

void dfs(int n, Point p1, Point p2) {
  if ( n == N ) return;

  double th = M_PI*60.0/180.0;
  Point s = {(2.0*p1.x+p2.x)/3.0, (2.0*p1.y+p2.y)/3.0};  
  Point t = {(p1.x+2.0*p2.x)/3.0, (p1.y+2.0*p2.y)/3.0};  
  Point u = {(t.x-s.x)*cos(th) - (t.y-s.y)*sin(th) + s.x,
	     (t.x-s.x)*sin(th) + (t.y-s.y)*cos(th) + s.y};	     

  dfs(n+1, p1, s);
  printf("%.8f %.8f\n", s.x, s.y);

  dfs(n+1, s, u);
  printf("%.8f %.8f\n", u.x, u.y);

  dfs(n+1, u, t);
  printf("%.8f %.8f\n", t.x, t.y);

  dfs(n+1, t, p2);
}

int main() {
  cin >> N;

  printf("%.8f %.8f\n", 0.0, 0.0);
  dfs(0, Point{0.0, 0.0}, Point{100.0, 0.0});  
  printf("%.8f %.8f\n", 100.0, 0.0);  
  
  return 0;
}

