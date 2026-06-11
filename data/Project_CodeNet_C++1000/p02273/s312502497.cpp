#include<bits/stdc++.h>
using namespace std;

struct Point
{
    double x,y;
};

void koch(int n,Point p1,Point p2)
{
    if(n==0)
    {
        return;
    }
    Point s,t,u;
    double th=M_PI*60.0/180.0;

    s.x=(2*p1.x+1*p2.x)/3.0;
    s.y=(2*p1.y+1*p2.y)/3.0;
    t.x=(1*p1.x+2*p2.x)/3.0;
    t.y=(1*p1.y+2*p2.y)/3.0;
    u.x=(t.x-s.x)*cos(th)-(t.y-s.y)*sin(th)+s.x;
    //cout<<u.x<<endl;
    u.y=(t.x-s.x)*sin(th)+(t.y-s.y)*cos(th)+s.y;
    //cout<<u.y<<endl;

    koch(n-1,p1,s);
    printf("%.8f %.8f\n",s.x,s.y);
    koch(n-1,s,u);
    printf("%.8f %.8f\n",u.x,u.y);
    koch(n-1,u,t);
    printf("%.8f %.8f\n",t.x,t.y);
    koch(n-1,t,p2);
}

int main()
{
    Point x,y;
    x.x=0;
    x.y=0;
    y.x=100;
    y.y=0;
    int n;
    cin>>n;
    printf("%.8f %.8f\n",x.x,x.y);
    koch(n,x,y);
    printf("%.8f %.8f\n",y.x,y.y);

	return 0;
}


