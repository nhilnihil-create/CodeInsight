#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

struct point{
    float x,y;
};

void kehe(point a,point b,int n){
    if(n==0){
        if(fabs(a.x-0.0)<0.000001)printf("%.6f %.6f\n",a.x,a.y);
        printf("%.6f %.6f\n",b.x,b.y);
    }
    else{
        double pi=M_PI/3.0;
        point p1,p2,p3;
        p1.x=2*a.x/3+b.x/3;
        p1.y=2*a.y/3+b.y/3;
        p3.x=a.x/3+2*b.x/3;
        p3.y=a.y/3+2*b.y/3;
        kehe(a,p1,n-1);
        p2.x=p1.x+(p3.x-p1.x)*cos(pi)-(p3.y-p1.y)*sin(pi);
        p2.y=p1.y+(p3.x-p1.x)*sin(pi)+(p3.y-p1.y)*cos(pi);
        kehe(p1,p2,n-1);
        kehe(p2,p3,n-1);
        kehe(p3,b,n-1);
    }
}

int main()
{
    int n;
    cin>>n;
    point a,b;
    a.x=0.0;a.y=0.0;
    b.x=100.0;b.y=0.0;
    kehe(a,b,n);
    return 0;
}
//int main(){
//    cout<<M_PI<<endl;
//    return 0;
//}