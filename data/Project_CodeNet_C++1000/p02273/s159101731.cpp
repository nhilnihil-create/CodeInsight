#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
struct point
{
    double x,y;
};
void koch(int n,point p1,point p2)
{
    if(n==0) return;
    point s,t,u;
    double th=M_PI*60/180;
    s.x=(2*p1.x+p2.x)/3;
    s.y=(2*p1.y+p2.y)/3;
    t.x=(p1.x+2*p2.x)/3;
    t.y=(p1.y+2*p2.y)/3;
    u.x=(t.x-s.x)*cos(th)-(t.y-s.y)*sin(th)+s.x;
    u.y=(t.x-s.x)*sin(th)+(t.y-s.y)*cos(th)+s.y;
    koch(n-1,p1,s);
    cout<<fixed<<setprecision(8)<<s.x<<" "<<s.y<<endl;
    koch(n-1,s,u);
    cout<<fixed<<setprecision(8)<<u.x<<" "<<u.y<<endl;
    koch(n-1,u,t);
    cout<<fixed<<setprecision(8)<<t.x<<" "<<t.y<<endl;
    koch(n-1,t,p2);
}
int main()
{
    int n;
    point p1,p2;
    p1.x=0;p1.y=0;
    p2.x=100;p2.y=0;
    cin>>n;
    cout<<fixed<<setprecision(8)<<p1.x<<" "<<p1.y<<endl;
    koch(n,p1,p2);
    cout<<fixed<<setprecision(8)<<p2.x<<" "<<p2.y<<endl;
    return 0;
}
