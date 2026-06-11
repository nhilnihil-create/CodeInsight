#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

typedef struct point{
    double x,y;
}P;

void koch(int ,P ,P );

int main(void)
{
    P a,b;
    int n;
    cin>>n;
    a.x=0;a.y=0;
    b.x=100;b.y=0;
    printf("%.8lf %.8lf\n",a.x,a.y);
    koch(n,a,b);
    printf("%.8lf %.8lf\n",b.x,b.y);
    return 0;
}

void koch(int n,P a,P b)
{
    if(n==0)return ;
    P s,t,u;
    double th=M_PI*60.0/180.0;
    s.x=(2.0*a.x+1.0*b.x)/3.0;
    s.y=(2.0*a.y+1.0*b.y)/3.0;
    t.x=(1.0*a.x+2.0*b.x)/3.0;
    t.y=(1.0*a.y+2.0*b.y)/3.0;
    u.x=(t.x-s.x)*cos(th)-(t.y-s.y)*sin(th)+s.x;
    u.y=(t.x-s.x)*sin(th)+(t.y-s.y)*cos(th)+s.y;
    
    koch(n-1,a,s);
    printf("%.8lf %.8lf\n",s.x,s.y);
    koch(n-1,s,u);
    printf("%.8lf %.8lf\n",u.x,u.y);
    koch(n-1,u,t);
    printf("%.8lf %.8lf\n",t.x,t.y);
    koch(n-1,t,b);
}

