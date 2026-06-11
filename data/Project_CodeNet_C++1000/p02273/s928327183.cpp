#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
#define pvec(vec) {for (auto v: vec) cout << v << ' '; cout << endl;}
#define pivec(vec) {rep(i, 0, vec.size()) cout << i << ':' << vec[i] << ' '; cout << endl;}

using namespace std;
using ll = long long;

struct Point
{
    double x, y;
    Point(double x, double y): x(x), y(y){}
    Point& operator+=(const Point& point)
    {
        x += point.x;
        y += point.y;
        return *this;
    }
    Point& operator=(const Point& point)
    {
        x = point.x;
        y = point.y;
        return *this;
    }
};

double mysin(double deg)
{
    return sin(M_PI*deg/180);
}

double mycos(double deg)
{
    return cos(M_PI*deg/180);
}

Point rotate(Point p, double deg)
{
    Point res(0, 0);
    res.x = mycos(deg)*p.x - mysin(deg) * p.y;
    res.y = mysin(deg)*p.x + mycos(deg) * p.y;
    return res;
}

vector<Point> res;
void kochCurve(int depth, Point strt, Point end)
{
    // finish condition
    if (depth == 0)
    {
        res.push_back(strt);
        return;
    }
    
    // make curve
    Point vec((end.x-strt.x)/3, (end.y - strt.y)/3);
    Point vec60 = rotate(vec, 60);
    Point vec300 = rotate(vec, 300);

    Point right = strt;
    vector<Point> moves = {vec, vec60, vec300, vec};
    for (auto move: moves)
    {
        Point left = right;
        right += move;
        kochCurve(depth-1, left, right);
    }
}

int main()
{
    // read input
    int depth;
    cin >> depth;

    // initialize res
    res.clear();

    // get curve
    Point strt(0,0);
    Point end(100, 0);
    kochCurve(depth, strt, end);
    res.push_back(end);

    // print out
    for (auto point: res)
        printf("%f %f\n", point.x, point.y);
    return 0;
}
