//
//  main.cpp
//  ALDS1_5_C
//
//  Created by ptyuan on 2018/10/27.
//  Copyright © 2018 Sy. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;


struct Point {
    double x;
    double y;
};

void koch(int n, Point a, Point b) {
    
    if (0 == n) {
        return;
    }
    
    Point s, u, t;
    double th = M_PI * 60.0 / 180.0;
    s.x = (2 * a.x + b.x) / 3;
    s.y = (2 * a.y + b.y) / 3;
    
    t.x = (a.x + 2 * b.x) / 3;
    t.y = (a.y + 2 * b.y) / 3;
    
    u.x = s.x + (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th);
    u.y = s.y + (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th);

    koch(n - 1, a, s);
    printf("%.8f %.8f\n", s.x, s.y);
    koch(n - 1, s, u);
    printf("%.8f %.8f\n", u.x, u.y);
    koch(n - 1, u, t);
    printf("%.8f %.8f\n", t.x, t.y);
    koch(n - 1, t, b);
}

int main(int argc, const char * argv[]) {
    int n = 0;
    scanf("%d", &n);
    Point a, b;
    a.x = 0;
    a.y = 0;
    
    b.x = 100;
    b.y = 0;
    printf("%.8f %.8f\n", a.x, a.y);
    koch(n, a, b);
    printf("%.8f %.8f\n", b.x, b.y);
    return 0;
}

