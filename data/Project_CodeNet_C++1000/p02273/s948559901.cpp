#include <bits/stdc++.h>
using namespace std;

struct point{
    double x, y;
    };
const double rot = M_PI / 3.0;
void koch(int n, point a, point b){
    if(n == 0) return;

    point s, t, u;
    s.x = (2.0 * a.x + 1.0 * b.x) / 3.0;//内分
    s.y = (2.0 * a.y + 1.0 * b.y) / 3.0;
    t.x = (1.0 * a.x + 2.0 * b.x) / 3.0;
    t.y = (1.0 * a.y + 2.0 * b.y) / 3.0;
    u.x = s.x + cos(rot) * (t.x - s.x) - sin(rot) * (t.y - s.y);//回転行列
    u.y = s.y + sin(rot) * (t.x - s.x) + cos(rot) * (t.y - s.y);

    koch(n - 1, a, s);
    printf("%.10f %.10f\n", s.x, s.y);
    koch(n - 1, s, u);
    printf("%.10f %.10f\n", u.x, u.y);
    koch(n - 1, u, t);
    printf("%.10f %.10f\n", t.x, t.y);
    koch(n - 1, t, b);
    return;
}

int main(){
    point p1, p2;
    int n;
    scanf("%d", &n);
    p1.x = 0;
    p1.y = 0;
    p2.x = 100;
    p2.y = 0;
    printf("%.10f %.10f\n", p1.x, p1.y);
    koch(n, p1, p2);
    printf("%.10f %.10f\n", p2.x, p2.y);
    return 0;
}

