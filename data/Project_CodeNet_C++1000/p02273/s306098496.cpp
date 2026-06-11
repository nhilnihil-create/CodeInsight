#include <iostream>
#include <stdio.h>
#include <math.h>

struct point {
    double x, y;
};

void koch(int d, point p1, point p2) {
    if ( d == 0 ) {
        return;
    }
    
    point s, t, u;
    double rad = M_PI * 60.0 / 180.0;
    s.x = ( 2*p1.x + 1*p2.x ) / 3;
    s.y = ( 2*p1.y + 1*p2.y ) / 3;
    t.x = ( 1*p1.x + 2*p2.x ) / 3;
    t.y = ( 1*p1.y + 2*p2.y ) / 3;
    u.x = ( t.x - s.x ) * cos( rad ) - ( t.y - s.y ) * sin( rad ) + s.x;
    u.y = ( t.x - s.x ) * sin( rad ) + ( t.y - s.y ) * cos( rad ) + s.y;
    
    koch(d-1, p1, s);
    printf("%.8f %.8f\n", s.x, s.y);
    koch(d-1, s, u);
    printf("%.8f %.8f\n", u.x, u.y);
    koch(d-1, u, t);
    printf("%.8f %.8f\n", t.x, t.y);
    koch(d-1, t, p2);
    //printf("%.8f %.8f\n", p2.x, p2.y);
}

int main() {
    int n;
    scanf("%d", &n);
    
    point p1, p2;
    p1.x = 0;
    p1.y = 0;
    p2.x = 100;
    p2.y = 0;
    printf("%.8f %.8f\n", p1.x, p1.y);
    koch(n, p1, p2);
    printf("%.8f %.8f\n", p2.x, p2.y);
    
    return 0;
}