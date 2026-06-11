#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

struct zahyou{
    double x, y;
};

void print_zahyou(zahyou z){
    printf("%.8lf %.8lf\n",z.x,z.y);
}

void koch(int d,zahyou p1,zahyou p2){
    zahyou s, u, t;
    if(d==0) return;
    s.x=(2*p1.x+1*p2.x)/3;
    s.y=(2*p1.y+1*p2.y)/3;
    t.x=(1*p1.x+2*p2.x)/3;
    t.y=(1*p1.y+2*p2.y)/3;
    u.x=(t.x-s.x)*cos(M_PI/3)-(t.y-s.y)*sin(M_PI/3)+s.x;
    u.y=(t.x-s.x)*sin(M_PI/3)+(t.y-s.y)*cos(M_PI/3)+s.y;
    koch(d-1,p1,s);
    print_zahyou(s);
    koch(d-1,s,u);
    print_zahyou(u);
    koch(d-1,u,t);
    print_zahyou(t);
    koch(d-1,t,p2);
}

int main(void){
    int n;
    zahyou p1,p2;
    p1.x=0.0;p1.y=0.0;
    p2.x=100.0;p2.y=0.0;
    cin >> n;
    printf("0.00000000 0.00000000\n");
    koch(n,p1,p2);
    print_zahyou(p2);
    return 0;
}