#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

struct point {
    double x;
    double y;
};

void koch(int d, point p1, point p2){
    if(d == 0){
        return;
    }

    point s, u, t;
    s.x = (2*p1.x + p2.x) / 3;
    s.y = (2*p1.y + p2.y) / 3;
    t.x = (p1.x + 2*p2.x) / 3;
    t.y = (p1.y + 2*p2.y) / 3;
    u.x = (t.x-s.x)*cos(M_PI/3) - (t.y-s.y)*sin(M_PI/3) + s.x;
    u.y = (t.x-s.x)*sin(M_PI/3) + (t.y-s.y)*cos(M_PI/3) + s.y;

    koch(d-1, p1, s);
    printf("%f %f\n", s.x, s.y);
    koch(d-1, s, u);
    printf("%f %f\n", u.x, u.y);
    koch(d-1, u, t);
    printf("%f %f\n", t.x, t.y);
    koch(d-1, t, p2);

    
}

int main() {
    int n; cin >> n;
    point p1 = {0, 0};
    point p2 = {100, 0};
    printf("%f %f\n", p1.x, p1.y);
    koch(n, p1, p2);
    printf("%f %f\n", p2.x, p2.y);
    return 0;
}
