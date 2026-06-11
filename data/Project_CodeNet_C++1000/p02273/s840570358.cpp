#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dl double long
#define rep(i, m, n) for(ll i = (ll)(m); i < (ll)(n); ++i)
#define rrep(i, m, n) for(ll i = (ll)(m); i < (ll)(n); --i)
const ll MOD = 1000000007;
const double pi = 3.14159265358979323846;

struct Point{
    double x, y;
};

void print(Point p){
    printf("%8f %8f\n", p.x, p.y);
    return;
}

void koch(int d, Point p1, Point p2){
    if(d == 0) return;
    Point s, t, u;
    s.x = (2 * p1.x + p2.x) / 3;
    s.y = (2 * p1.y + p2.y) / 3;
    t.x = (p1.x + 2 * p2.x) / 3;
    t.y = (p1.y + 2 * p2.y) / 3;
    u.x = (t.x - s.x) * cos(pi/3) - (t.y - s.y) * sin(pi/3) + s.x;
    u.y = (t.y - s.y) * cos(pi/3) + (t.x - s.x) * sin(pi/3) + s.y;

    koch(d-1, p1, s);
    print(s);
    koch(d-1, s, u);
    print(u);
    koch(d-1, u, t);
    print(t);
    koch(d-1, t, p2);
    return;
}

int main(void){
    int n;
    cin >> n;
    Point start, end;
    start.x = start.y = end.y = 0;
    end.x = 100;
    print(start);
    koch(n, start, end);
    print(end);

    return 0;
}
