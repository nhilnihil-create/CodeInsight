#include <stdio.h>
#include <math.h>

typedef struct Point{
    double x;
    double y;
} Point;

void koch(int d, Point p1, Point p2){
    if (d == 0) return;
    Point s, u, t;
    // [calc points]
    // --- s ---
    s.x = (2*p1.x + p2.x) / 3;
    s.y = (2*p1.y + p2.y) / 3;
    // --- t ---
    t.x = (p1.x + 2*p2.x) / 3;
    t.y = (p1.y + 2*p2.y) / 3;
    // --- u ---
    double th = M_PI * 60.0 / 180.0;
    u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
    u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;
    // 常に水平ではないため、下記はNG
    // u.x = (p1.x + p2.x) / 2;
    // u.y = p1.y + ((p2.x - p1.x) / 3.0) * sin(M_PI * 60.0 / 180.0);
    // [recursive]
    koch(d - 1, p1, s);
    printf("%.8f %.8f\n", s.x, s.y);
    koch(d - 1, s, u);
    printf("%.8f %.8f\n", u.x, u.y);
    koch(d - 1, u, t);
    printf("%.8f %.8f\n", t.x, t.y);
    koch(d - 1, t, p2);
}

int main(){
    int n;
    scanf("%d", &n);
    Point p1 = {0.0, 0.0};
    Point p2 = {100.0, 0.0};

    printf("%.8f %.8f\n", p1.x, p1.y);
    koch(n, p1, p2);
    printf("%.8f %.8f\n", p2.x, p2.y);

    return 0;
}


