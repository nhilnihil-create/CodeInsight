#include <bits/stdc++.h>
using namespace std;


constexpr double PI = 3.14159265358979;


//Point
struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y){}
    friend ostream& operator<<(ostream& os, const Point& p){ return os << '(' << p.x << ", " << p.y << ')'; }
};
inline Point operator+(const Point& p, const Point& q){ return Point(p.x+q.x, p.y+q.y); }
inline Point operator-(const Point& p, const Point& q){ return Point(p.x-q.x, p.y-q.y); }
inline Point operator*(const Point& p, double a){ return Point(p.x*a, p.y*a); }
inline Point operator*(double a, const Point& p){ return Point(a*p.x, a*p.y); }
inline Point operator/(const Point& p, double a){ return Point(p.x/a, p.y/a); }
inline Point rot(const Point& p, double ang){ return Point(cos(ang)*p.x-sin(ang)*p.y, sin(ang)*p.x+cos(ang)*p.y); }
inline double norm(const Point& p){ return p.x*p.x+p.y*p.y; }
inline double abs(const Point& p){ return sqrtl(norm(p)); }


void rec(Point p1, Point p2, int l){
    if(l == 0){ cout << fixed << setprecision(10) << p1.x << ' ' << p1.y << endl; return; }
    auto s = p1+(p2-p1)/3;
    auto t = p1+2*(p2-p1)/3;
    auto u = s+rot(t-s, PI/3);
    rec(p1, s, l-1);
    rec(s, u, l-1);
    rec(u, t, l-1);
    rec(t, p2, l-1);
}


int n;


int main(){
    cin >> n;
    rec(Point(0, 0), Point(100, 0), n);
    cout << fixed << setprecision(10) << 100.0 << ' ' << 0.0 << endl;

    return 0;
}
