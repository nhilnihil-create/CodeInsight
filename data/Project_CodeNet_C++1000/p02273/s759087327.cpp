#include <cmath>
#include <iostream>
#include <algorithm>
#include <list>

struct Point
{
    double x;
    double y;
};
typedef std::list<Point> List;
Point GetU(const Point& s, const Point& t)
{
    const double thete = 60. / 180. * M_PI;
    Point st = {t.x - s.x, t.y - s.y};
    Point su = {st.x * std::cos(thete) - st.y * std::sin(thete), st.x * std::sin(thete) + st.y * std::cos(thete)};
    Point u = {s.x + su.x, s.y + su.y};
    return u;
}
void InsertKochCurve(List& list, List::iterator p1, List::iterator p2, int n)
{
    if(!n) return;
    double x = (p2->x - p1->x) / 3;
    double y = (p2->y - p1->y) / 3;
    Point s = {p1->x + x, p1->y + y};
    Point t = {p2->x - x, p2->y - y};
    Point u = GetU(s, t);
    List::iterator ti = list.insert(p2, t);
    List::iterator ui = list.insert(ti, u);
    List::iterator si = list.insert(ui, s);
    
    InsertKochCurve(list, p1, si, n - 1);
    InsertKochCurve(list, si, ui, n - 1);
    InsertKochCurve(list, ui, ti, n - 1);
    InsertKochCurve(list, ti, p2, n - 1);
}
void Output(const List& list)
{
    for(List::const_iterator i = list.begin();
        i != list.end();
        ++i)
    {
        std::cout << i->x << " " << i->y << std::endl;
    }
}

int main()
{
    int n;
    std::cin >> n;
    List list;
    Point alpha = {  0, 0};
    Point omega = {100, 0};
    list.push_back(alpha);
    list.push_back(omega);
    InsertKochCurve(list, list.begin(), --list.end(), n);
    Output(list);
    return 0;
}