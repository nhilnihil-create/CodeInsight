#include <bits/stdc++.h>
using namespace std;

struct Point{
    double x;
    double y;
};

void koch(int n, Point p1, Point p2){
    if(n==0) return;
    Point s,u,t;
    double th = M_PI*(60.0/180.0);
    s.x = (p1.x*2+p2.x*1)/3;
    s.y = (p1.y*2+p2.y*1)/3;
    t.x = (p1.x*1+p2.x*2)/3;
    t.y = (p1.y*1+p2.y*2)/3;
    u.x = (t.x-s.x)*cos(th) - (t.y-s.y)*sin(th) + s.x;
    u.y = (t.x-s.x)*sin(th) + (t.y-s.y)*cos(th) + s.y;

    koch(n-1,p1,s);
    printf("%.8f %.8f\n",s.x,s.y);
    koch(n-1,s,u);
    printf("%.8f %.8f\n",u.x,u.y);
    koch(n-1,u,t);
    printf("%.8f %.8f\n",t.x,t.y);
    koch(n-1,t,p2);
}

int main(){
    int n;
    scanf("%d",&n);
    Point p1, p2;
    p1.x = p1.y = p2.y = 0.0;
    p2.x = 100.0;
    printf("%.8f %.8f\n",p1.x,p1.y);
    koch(n,p1,p2);
    printf("%.8f %.8f\n",p2.x,p2.y);
    return 0;
}

