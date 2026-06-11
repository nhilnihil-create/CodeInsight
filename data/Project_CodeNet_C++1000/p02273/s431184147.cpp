#include <cmath>
#include <iostream>
#include <algorithm>
#include <list>

struct Point
{
    double x;
    double y;
};
Point GetU(const Point& s, const Point& t)
{
    const double thete = 60. / 180. * M_PI;
    Point st = {t.x - s.x, t.y - s.y};
    Point su = {st.x * std::cos(thete) - st.y * std::sin(thete), st.x * std::sin(thete) + st.y * std::cos(thete)};
    Point u = {s.x + su.x, s.y + su.y};
    return u;
}
void Print(const Point& p)
{
    std::cout << p.x << " " << p.y << std::endl;
    
}
void KochCurve(const Point& p1, const Point& p2, int n)
{
    if(!n) return;
    double x = (p2.x - p1.x) / 3;
    double y = (p2.y - p1.y) / 3;
    Point s = {p1.x + x, p1.y + y};
    Point t = {p2.x - x, p2.y - y};
    Point u = GetU(s, t);
    
    // Print(p1);
    KochCurve(p1, s, n - 1);
    Print(s);
    KochCurve(s, u, n - 1);
    Print(u);
    KochCurve(u, t, n - 1);
    Print(t);
    KochCurve(t, p2, n - 1);
    // Print(p2);
}

int main()
{
    int n;
    std::cin >> n;
    Point alpha = {  0, 0};
    Point omega = {100, 0};
    Print(alpha);
    KochCurve(alpha, omega, n);
    Print(omega);
    return 0;
}