#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PI M_PI

struct Point {
    double x;
    double y;

    void prt(){
        printf("%.8f %.8f\n",x,y);
    }
};

void koch(int n,Point p1,Point p2){
    if(n==0) return ;
    Point s,t,u;
    s.x = (2*p1.x + p2.x) / 3;
    s.y = (2*p1.y + p2.y) / 3;
    t.x = (p1.x + 2*p2.x) / 3;
    t.y = (p1.y + 2*p2.y) / 3;
    u.x = (t.x - s.x)*cos(PI/3) - (t.y - s.y)*sin(PI/3) + s.x;
    u.y = (t.x - s.x)*sin(PI/3) + (t.y - s.y)*cos(PI/3) + s.y;

    koch(n-1, p1, s);
    s.prt();
    koch(n-1, s, u);
    u.prt();
    koch(n-1, u, t);
    t.prt();
    koch(n-1, t , p2);
}

int main(){
    int n;
    cin >> n;
    Point s,g;
    s.x=s.y=g.y=0;
    g.x=100;
    s.prt();
    koch(n,s,g);
    g.prt();
}

