#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point{double x, y;};

vector<pair<double, double> > A;

void Koch(int n, Point a, Point b){
    if(n == 0) return;
    Point s, t, u;
    double th = M_PI / 3.0;

    s.x = (2.0 * a.x + 1.0 * b.x) / 3.0;
    s.y = (2.0 * a.y + 1.0 * b.y) / 3.0;
    t.x = (1.0 * a.x + 2.0 * b.x) / 3.0;
    t.y = (1.0 * a.y + 2.0 * b.y) / 3.0;
    u.x = cos(th) * (t.x - s.x) - sin(th) * (t.y - s.y) + s.x;
    u.y = sin(th) * (t.x - s.x) + cos(th) * (t.y - s.y) + s.y;

    Koch(n-1, a, s);
    cout << setprecision(8) << s.x << " " << s.y << endl;
    Koch(n-1, s, u);
    cout << setprecision(8) << u.x << " " << u.y << endl;
    Koch(n-1, u, t);
    cout << setprecision(8) << t.x << " " << t.y << endl;
    Koch(n-1, t, b);
}

int main(){
    int n;
    cin >> n;
    Point a, b;
    a.x = a.y = b.y = 0.0;
    b.x = 100.0;
    cout << fixed;
    cout << setprecision(8) << a.x << " " << a.y << endl;
    Koch(n, a, b);
    cout << setprecision(8) << b.x << " " << b.y << endl;
    return 0;
}
    
