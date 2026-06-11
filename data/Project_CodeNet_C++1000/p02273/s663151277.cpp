#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

class vec {
public:
  double x;
  double y;
  vec(double nx, double ny) :x{nx}, y{ny} {}
};

class segment {
public:
  vec start;
  vec end;
  segment(vec start, vec end) :start{start}, end{end} {}
};

vec operator+(vec v1, vec v2) {
  return vec(v1.x+v2.x, v1.y+v2.y);
}

vec operator-(vec v1, vec v2) {
  return vec(v1.x-v2.x, v1.y-v2.y);
}

vec operator*(double a, vec v) {
  return vec(a*v.x, a*v.y);
}

vec operator*(vec v, double a) {
  return a*v;
}

vec rot90ccw(vec v) {
  return vec(-1.*v.y, v.x);
}

// post: splits the segment `s` into four resulting segments
// and enqueues them, in increasing Koch curve order, into
// `dest`
void split_and_add(segment& s, queue<segment>& dest)
{
  vec mid1 = (2./3)*(s.start) + (1./3)*(s.end);
  vec mid2 = (1./3)*s.start + (2./3)*s.end;
  vec triangle_top = rot90ccw((mid2-mid1)*0.5*sqrt(3.)) + 0.5*(mid1 + mid2);
  dest.push(segment(s.start, mid1));
  dest.push(segment(mid1, triangle_top));
  dest.push(segment(triangle_top, mid2));
  dest.push(segment(mid2, s.end));
}

int main()
{
  int n; cin >> n; // number of iterations
  queue<segment> q;
  q.push(segment(vec(0,0), vec(100,0)));
  for (int i = 0; i < n; ++i) {
    queue<segment> q2;
    while (!q.empty()) {
      segment &s = q.front();
      split_and_add(s, q2);
      q.pop();
    }
    q = move(q2);
  }
  cout << fixed;
  cout << q.front().start.x << " " << q.front().start.y << endl;
  while (!q.empty()) {
    segment &s = q.front();
    cout << s.end.x << " " << s.end.y << endl;
    q.pop();
  }
}
