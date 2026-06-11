#include<cmath>
#include<iostream>
#define x first
#define y second
using namespace std;
void koch(int n, auto s, auto e){
    if(n == 0) return;
    const double th = acos(-1) / 3;
    pair<double, double> a, b, c;
    a.x = (2 * s.x + e.x) / 3;
    a.y = (2 * s.y + e.y) / 3;
    c.x = (s.x + 2 * e.x) / 3;
    c.y = (s.y + 2 * e.y) / 3;
    b.x = (c.x - a.x) * cos(th) - (c.y - a.y) * sin(th) + a.x;
    b.y = (c.x - a.x) * sin(th) + (c.y - a.y) * cos(th) + a.y;
    koch(n-1, s, a);
    printf("%.8f %.8f\n", a.x, a.y);
    koch(n-1, a, b);
    printf("%.8f %.8f\n", b.x, b.y);
    koch(n-1, b, c);
    printf("%.8f %.8f\n", c.x, c.y);
    koch(n-1, c, e);
}
int main(){
    pair<double, double> s, e;
    s.x = s.y = e.y = 0;
    e.x = 100;
    int n;
    cin>>n;
    printf("%.8f %.8f\n", s.x, s.y);
    koch(n, s, e);
    printf("%.8f %.8f\n", e.x, e.y);
}