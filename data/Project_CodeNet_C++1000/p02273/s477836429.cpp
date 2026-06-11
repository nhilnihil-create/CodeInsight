#include <stdio.h>
#include <cmath>

using namespace std;
struct point{
    double x;
    double y;
};
void koch(int d, point p1, point p2){
    if(d==0) return;
    point s,u,t;
    double theta=60*M_PI/180;
    s.x=(2*p1.x+p2.x)/3;s.y=(2*p1.y+p2.y)/3;
    t.x=(p1.x+2*p2.x)/3;t.y=(p1.y+2*p2.y)/3;
    u.x=(t.x-s.x)*cos(theta) - (t.y-s.y)*sin(theta)+s.x;
    u.y=(t.x-s.x)*sin(theta) + (t.y-s.y)*cos(theta)+s.y;
    koch(d-1,p1,s);
    printf("%.8f %.8f\n",s.x,s.y);
    koch(d-1,s,u);
    printf("%.8f %.8f\n",u.x,u.y);
    koch(d-1,u,t);
    printf("%.8f %.8f\n",t.x,t.y);
    koch(d-1,t,p2);


}

int main()
{
    int d;
    scanf("%d",&d);

    point start,end;
    start.x=0; start.y=0;
    end.x=100; end.y=0;
    printf("%.8f %.8f\n",start.x,start.y);
    koch(d,start,end);
    printf("%.8f %.8f\n",end.x,end.y);


    return 0;
}
