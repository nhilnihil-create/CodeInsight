#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define sqrtts sqrt(3)/2
struct point{double x;double y;};
using namespace std;
point uepoint(point p1,point p2){
    point p3;
    p3.x=(p1.x+p2.x)/2-(p2.y-p1.y)*sqrtts;
    p3.y=(p1.y+p2.y)/2+(p2.x-p1.x)*sqrtts;
    return p3;
}

void koch(int n,point p1,point p2){
    if(n==0)return;
    point p3,p4,p5;
    p3.x=(2*p1.x+p2.x)/3;
    p3.y=(2*p1.y+p2.y)/3;
    p4.x=(p1.x+2*p2.x)/3;
    p4.y=(p1.y+2*p2.y)/3;
    p5=uepoint(p3,p4);
    koch(n-1,p1,p3);
    printf("%.8lf %.8lf\n",p3.x,p3.y);
    koch(n-1,p3,p5);
    printf("%.8lf %.8lf\n",p5.x,p5.y);
    koch(n-1,p5,p4);
    printf("%.8lf %.8lf\n",p4.x,p4.y);
    koch(n-1,p4,p2);
}

int main(void){
    int n;
    cin>>n;
    point p1,p2;
    p1.x=0;
    p1.y=0;
    p2.x=100;
    p2.y=0;
    printf("%.8lf %.8lf\n",p1.x,p1.y);
    koch(n,p1,p2);
    printf("%.8lf %.8lf\n",p2.x,p2.y);
}
