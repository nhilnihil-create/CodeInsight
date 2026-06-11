#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <limits>
#include <stdio.h>
using namespace std;

struct Pos
{
    double x;
    double y;
};
void print(struct Pos p)
{
    printf("%.6lf %.6lf\n", p.x, p.y);
}
void kock(int n, struct Pos p1, struct Pos p2)
{
    if(n == 0) return;
    
    struct Pos s,t,u;
    static const double pi = 3.141592653589793;
    s.x = (2*p1.x + 1*p2.x) / 3.0;
    s.y = (2*p1.y + 1*p2.y) / 3.0;
    t.x = (1*p1.x + 2*p2.x) / 3.0;
    t.y = (1*p1.y + 2*p2.y) / 3.0;
    double rad60 = pi/(180.0/60.0);
    u.x = (t.x-s.x)*cos(rad60) - (t.y-s.y)*sin(rad60) + s.x; 
    u.y = (t.x-s.x)*sin(rad60) + (t.y-s.y)*cos(rad60) + s.y; 
    
    kock(n-1, p1, s); print(s);
    kock(n-1, s,  u); print(u);
    kock(n-1, u,  t); print(t);
    kock(n-1, t, p2);
}
int main()
{
    int n;
    cin >> n;
    
    struct Pos p1, p2;
    print(p1);
    p1.x = 0.0, p1.y = 0.0;
    p2.x = 100.0, p2.y = 0.0;
    kock(n, p1, p2);
    print(p2);
}
