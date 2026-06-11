#include <iostream>
#include <cstdlib>
#include <math.h>
#include <iomanip>
using namespace std;

struct Point { double x, y; };

void koch(int n, Point a, Point b){
    if(n == 0) return;
    Point s,t,u;
    double th = M_PI * 60.0 / 180.0;
    s.x = (2*a.x + b.x)/3;
    s.y = (2*a.y + b.y)/3;
    t.x = (a.x + 2*b.x)/3;
    t.y = (a.y + 2*b.y)/3;
    u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
    u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;
    koch(n-1, a, s);
    cout << fixed << setprecision(8) << s.x << " " << s.y << endl;
    koch(n-1, s, u);
    cout << fixed << setprecision(8) << u.x << " " << u.y << endl;
    koch(n-1, u, t);
    cout << fixed << setprecision(8) << t.x << " " << t.y << endl;;
    koch(n-1, t, b);    
    }    

int main()
{
    Point a, b;
    a.x = 0.0; a.y = 0.0;
    b.x = 100.0; b.y = 0.0;
    int n;
    cin >> n;
    cout << fixed << setprecision(8) << 0.0 << " " << 0.0 << endl;;
    koch(n, a, b);
    cout << fixed << setprecision(8) << 100.0 << " " << 0.0 << endl;;
    return 0;
}

