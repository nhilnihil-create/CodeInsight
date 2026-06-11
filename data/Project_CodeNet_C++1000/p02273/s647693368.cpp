#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

typedef struct Point {
    double x;
    double y;
} Point;

Point rotate(Point a, Point b, double deg)
{
    double rad = M_PI * deg / 180;
    double x = (b.x - a.x) * cos(rad) - (b.y - a.y) * sin(rad) + a.x;
    double y = (b.x - a.x) * sin(rad) + (b.y - a.y) * cos(rad) + a.y;

    return Point{x, y};
}

Point internally_dividing_point(Point a, Point b, double m, double n)
{
    double x = (n * a.x + m * b.x) / (m + n);
    double y = (n * a.y + m * b.y) / (m + n);
    return Point{x, y};
}

queue<Point> koch_curve(int n)
{
    queue<Point> new_curve;
    new_curve.push(Point{0.0,0.0});

    if (n == 0) {
        new_curve.push(Point{100.0,0.0});
        return new_curve;
    } else {
        auto curve = koch_curve(n-1);
        auto length = curve.size();

        for (size_t i = 0; i < length - 1; i++) {
            auto a = curve.front();
            curve.pop();
            auto b = curve.front();

            auto s = internally_dividing_point(a, b, 1, 2);
            auto t = internally_dividing_point(a, b, 2, 1);
            auto u = rotate(s, t, 60);

            new_curve.push(s);
            new_curve.push(u);
            new_curve.push(t);
            new_curve.push(b);
        }

        return new_curve;
    }
}

void print_curve(queue<Point> curve)
{
    for (auto a = curve.front(); !curve.empty() ; curve.pop(), a = curve.front())
        cout << a.x << " " << a.y << endl;
}

int main(void)
{
    int n;
    cin >> n;
    print_curve(koch_curve(n));
    return 0;
}