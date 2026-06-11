#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
int n;

class point{
public:
  double x, y;
};

void func(point p1, point p2, int id){
  if(id == n) return;
  point s, t, u;
  s.x = (2 * p1.x + p2.x) / 3;
  s.y = (2 * p1.y + p2.y) / 3;
  t.x = (p1.x + 2 * p2.x) / 3;
  t.y = (p1.y + 2 * p2.y) / 3;
  u.x = (t.x - s.x) * cos(M_PI / 3.0) - (t.y - s.y) * sin(M_PI / 3.0) + s.x;
  u.y = (t.x - s.x) * sin(M_PI / 3.0) + (t.y - s.y) * cos(M_PI / 3.0) + s.y;
  func(p1, s, id + 1);
  cout << s.x << " " << s.y << endl;
  func(s, u, id + 1);
  cout << u.x << " " << u.y << endl;
  func(u, t, id + 1);
  cout << t.x << " " << t.y << endl;
  func(t, p2, id + 1);
  return;
}

void solve(){
  cin >> n;
  point p1, p2;
  p1.x = 0;
  p1.y = 0;
  p2.x = 100;
  p2.y = 0;
  cout << p1.x << " " << p1.y << endl;
  func(p1, p2, 0);
  cout << p2.x << " " << p2.y << endl;
  return;
}

int main(){
  solve();
  return 0;
}

