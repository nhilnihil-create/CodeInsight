#include <cstdio>
#include <cmath>
using namespace std;
constexpr double pi = 3.141592653589793;
const double cos_60 = cos(pi / 3.0), sin_60 = sin(pi / 3.0);

struct Point
{
    double x, y;
};

void koch(int d, Point p_1, Point p_2)
{
    if (d == 0)
    {
        return;
    }

    Point s, t, u;
    s.x = p_1.x * 2.0 / 3.0 + p_2.x / 3.0;
    s.y = p_1.y * 2.0 / 3.0 + p_2.y / 3.0;
    t.x = p_1.x / 3.0 + p_2.x * 2.0 / 3.0;
    t.y = p_1.y / 3.0 + p_2.y * 2.0 / 3.0;
    u.x = (t.x - s.x) * cos_60 - (t.y - s.y) * sin_60 + s.x;
    u.y = (t.x - s.x) * sin_60 + (t.y - s.y) * cos_60 + s.y;
    koch(d - 1, p_1, s);
    printf("%lf %lf\n", s.x, s.y);
    koch(d - 1, s, u);
    printf("%lf %lf\n", u.x, u.y);
    koch(d - 1, u, t);
    printf("%lf %lf\n", t.x, t.y);
    koch(d - 1, t, p_2);
}

int main()
{
    int n;
    scanf("%d", &n);
    Point p_1, p_2;
    p_1.x = 0.0;
    p_1.y = 0.0;
    p_2.x = 100.0;
    p_2.y = 0.0;

    printf("%lf %lf\n", p_1.x, p_1.y);
    koch(n, p_1, p_2);
    printf("%lf %lf\n", p_2.x, p_2.y);
    return 0;
}
