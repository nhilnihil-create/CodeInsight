#include <cstdio>
#include <cmath>
using namespace std;

struct P { double x, y; };

void print(P p) {
}

void dfs(P a, P b, int d) {
    if (d == 0) return;

    double th = M_PI * 60.0 / 180.0;
    P s, t, u;

    s.x = (2.0 * a.x + 1.0 * b.x) / 3.0;
    s.y = (2.0 * a.y + 1.0 * b.y) / 3.0;
    t.x = (1.0 * a.x + 2.0 * b.x) / 3.0;
    t.y = (1.0 * a.y + 2.0 * b.y) / 3.0;
    u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
    u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

    dfs(a, s, d - 1);
    printf("%.8f %.8f\n", s.x, s.y);
    dfs(s, u, d - 1);
    printf("%.8f %.8f\n", u.x, u.y);
    dfs(u, t, d - 1);
    printf("%.8f %.8f\n", t.x, t.y);
    dfs(t, b, d - 1);
}

int main(void) {
    int n;
    P a, b;
    a.x = 0; a.y = 0;
    b.x = 100; b.y = 0;
    scanf("%d", &n);

    printf("%.8f %.8f\n", a.x, a.y);
    dfs(a, b, n);
    printf("%.8f %.8f\n", b.x, b.y);

    return 0;
}