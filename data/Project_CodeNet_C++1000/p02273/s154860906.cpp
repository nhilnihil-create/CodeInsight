#include <cstdio>
#include <cmath>

using namespace std;

#define rep(i, N) for (ll i = 0; i < N; ++i)
typedef long long int ll;

struct Point {
    double x, y;
};

void print(Point p) {
    printf("%.8f %.8f\n", p.x, p.y);
}

void koch(int n, Point p1, Point p2) {
    if (n == 0) return;
    double th = M_PI * 60.0 / 180.0;
    Point s, t, u;
    s.x = (2.0 * p1.x + 1.0 * p2.x) / 3.0;
    s.y = (2.0 * p1.y + 1.0 * p2.y) / 3.0;
    t.x = (1.0 * p1.x + 2.0 * p2.x) / 3.0;
    t.y = (1.0 * p1.y + 2.0 * p2.y) / 3.0;
    // 三平方の定理 - 回転行列
    u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
    u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

    koch(n - 1, p1, s);
    print(s);
    koch(n - 1, s, u);
    print(u);
    koch(n - 1, u, t);
    print(t);
    koch(n - 1, t, p2);
}

int main() {
    int n;
    scanf("%d", &n);
    Point p1 = {0, 0};
    Point p2 = {100, 0};
    print(p1);
    koch(n, p1, p2);
    print(p2);

    return 0;
}

