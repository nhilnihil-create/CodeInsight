#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int n;

typedef struct Point
{
    double x;
    double y;
} P;

void KochCurve(P p1, P p2, int i)
{
    if (i == n)
    {
        printf("%.8lf %.8lf\n", p1.x, p1.y);
        return;
    }
    else
    {
        P s, u, t;
        s.x = p1.x + (p2.x - p1.x) / 3;
        s.y = p1.y + (p2.y - p1.y) / 3;
        t.x = p1.x + (p2.x - p1.x) * 2 / 3;
        t.y = p1.y + (p2.y - p1.y) * 2 / 3;
        u.x = s.x + (p2.x - p1.x) / 6 - (p2.y - p1.y) * sqrt(3.0) / 6;
        u.y = s.y + (p2.x - p1.x) * sqrt(3.0) / 6 + (p2.y - p1.y) / 6;
        KochCurve(p1, s, i + 1);
        KochCurve(s, u, i + 1);
        KochCurve(u, t, i + 1);
        KochCurve(t, p2, i + 1);
    }
}

int main()
{
    cin >> n;
    P p1, p2;
    p1.x = 0;
    p1.y = 0;
    p2.x = 100;
    p2.y = 0;
    KochCurve(p1, p2, 0);
    printf("%.8lf %.8lf\n", p2.x, p2.y);
    return 0;
}
