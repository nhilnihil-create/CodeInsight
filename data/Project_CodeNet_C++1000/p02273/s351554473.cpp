#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
typedef struct point{
    double x,y;
} P;
void show(P p)
{
    cout<<fixed<<setprecision(5);
    cout<<p.x<<' '<<p.y<<endl;
}
void work(P p1,P p2,int n)
{
    if(n==0)
        return;
    P p3,p4,p5;
    double dx,dy,a,b;
    p3.x = 2./3*p1.x+p2.x/3;
    p3.y = 2./3*p1.y+p2.y/3;
    p4.x = 1./3*p1.x+p2.x*2/3;
    p4.y = 1./3*p1.y+p2.y*2/3;
    dx = p4.x-p3.x;
    dy = p4.y-p3.y;
    a = 0.5;
    b = sqrt(3)/2;
    p5.x = p3.x+a*dx-b*dy;
    p5.y = p3.y+dx*b+a*dy;
    work(p1,p3,n-1);
    show(p3);
    work(p3,p5,n-1);
    show(p5);
    work(p5,p4,n-1);
    show(p4);
    work(p4,p2,n-1);
}
int main()
{
    int n;
    P p1,p2;
    p1.x = p1.y = 0;
    p2.x = 100;
    p2.y = 0;
    cin>>n;
    show(p1);
    work(p1,p2,n);
    show(p2);
    return 0;
}