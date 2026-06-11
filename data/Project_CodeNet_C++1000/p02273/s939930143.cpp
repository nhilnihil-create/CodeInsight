#include <cmath>
#include <cstdio>
#include <utility>

using namespace std;

typedef pair<double, double> point;

double th = M_PI * 60.0 / 180.0;

void koch(int n, point p1, point p2) {
    if (n == 0) return;
    double s_x = (p1.first * 2 + p2.first) / 3;
    double s_y = (p1.second * 2 + p2.second) / 3;
    double t_x = (p1.first + p2.first * 2) / 3;
    double t_y = (p1.second + p2.second * 2) / 3;
    double u_x = (t_x - s_x) * cos(th) - (t_y - s_y) * sin(th) + s_x;
    double u_y = (t_x - s_x) * sin(th) + (t_y - s_y) * cos(th) + s_y;
    
    point s = make_pair(s_x, s_y);
    point t = make_pair(t_x, t_y);
    point u = make_pair(u_x, u_y);

    koch(n - 1, p1, s);
    printf("%.8f %.8f\n", s.first, s.second);
    koch(n - 1, s, u);
    printf("%.8f %.8f\n", u.first, u.second);
    koch(n - 1, u, t);
    printf("%.8f %.8f\n", t.first, t.second);
    koch(n - 1, t, p2);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%.8f %.8f\n", 0.0, 0.0);
    koch(n, make_pair(0.0,0.0), make_pair(100.0, 0.0));
    printf("%.8f %.8f\n", 100.0, 0.0);
}

