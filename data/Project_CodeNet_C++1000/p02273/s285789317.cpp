#include<iostream>
#include<string>
#include<math.h>
#include<iomanip>
using namespace std;

int n;

long double pi = 3.141592653;

struct Node{
  long double x;
  long double y;
};

void koch(int d, Node p1, Node p2){
  if(d == 0) return;

  Node s, t, u;

  s.x = (2 * p1.x + 1 * p2.x) / 3;
  s.y = (2 * p1.y + 1 * p2.y) / 3;
  t.x = (1 * p1.x + 2 * p2.x) / 3;
  t.y = (1 * p1.y + 2 * p2.y) / 3;
  u.x = (t.x - s.x) * cos(pi / 3) - (t.y - s.y) * sin(pi / 3) + s.x;
  u.y = (t.x - s.x) * sin(pi / 3) + (t.y - s.y) * cos(pi / 3) + s.y;

  koch(d - 1, p1, s);
  cout << std::setprecision(8) <<  s.x << ' ' << s.y << endl;
  koch(d - 1, s, u);
  cout << std::setprecision(8)<< u.x << ' ' << u.y << endl;
  koch(d - 1, u, t);
  cout << std::setprecision(8)<< t.x << ' ' << t.y << endl;
  koch(d - 1, t, p2);

}

int main(){

  cin >> n;

  Node p1, p2;

  p1.x = 0.0;

  p1.y = 0.0;

  p2.x = 100.0;

  p2.y = 0.0;

  cout << fixed;

  cout << std::setprecision(8)<< p1.x << ' ' << p1.y << endl;

  koch(n, p1, p2);

  cout << std::setprecision(8)<< p2.x << ' ' << p2.y << endl;
  return 0;
}

