#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

class Point
{
public:
   double x;
   double y;
};

void koch(int n, Point a, Point b){
   if(n == 0) return;

   Point s, u, t;
   double si60 = sqrt(3.0)/2.0;
   double co60 = 0.5;

   s.x = (a.x + a.x + b.x) / 3.0;
   s.y = (a.y + a.y + b.y) / 3.0;
   t.x = (a.x + b.x + b.x) / 3.0;
   t.y = (a.y + b.y + b.y) / 3.0;
   u.x = (t.x - s.x) * co60 - (t.y - s.y) * si60 + s.x;
   u.y = (t.x - s.x) * si60 + (t.y - s.y) * co60 + s.y;

   koch(n-1, a, s);
   printf("%.8f %.8f\n", s.x, s.y);
   koch(n-1, s, u);
   printf("%.8f %.8f\n", u.x, u.y);
   koch(n-1, u, t);
   printf("%.8f %.8f\n", t.x, t.y);
   koch(n-1, t, b);
}

int main(){
   int n;
   Point a, b;
   a.x = 0.0;
   a.y = 0.0;
   b.x = 100.0;
   b.y = 0.0;
   cin >> n;
   printf("%.8f %.8f\n", a.x, a.y);
   koch(n, a, b);
   printf("%.8f %.8f\n", b.x, b.y);
   return 0;
}
