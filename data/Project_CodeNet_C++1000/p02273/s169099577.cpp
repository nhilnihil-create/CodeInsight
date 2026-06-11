#include<iostream>
#include<cstdio>
#include<cmath>
int n;

struct Point{
        double x;
        double y;
};

void calc(int m,Point p1,Point p2){
        if(m>=n){
                return;
        }
        Point s,t,u;
        s.x=(2.0*p1.x+p2.x)/3.0;
        s.y=(2.0*p1.y+p2.y)/3.0;
        t.x=(p1.x+2.0*p2.x)/3.0;
        t.y=(p1.y+2.0*p2.y)/3.0;
        u.x=(t.x-s.x)*(1.0/2.0)-(t.y-s.y)*(sqrt(3.0)/2.0)+s.x;
        u.y=(t.x-s.x)*(sqrt(3.0)/2.0)+(t.y-s.y)*(1.0/2.0)+s.y;
        calc(m+1,p1,s);
        printf("%.8f %.8f\n",s.x,s.y);
        calc(m+1,s,u);
        printf("%.8f %.8f\n",u.x,u.y);
        calc(m+1,u,t);
        printf("%.8f %.8f\n",t.x,t.y);
        calc(m+1,t,p2);
}

int main(){
        std::cin>>n;
        Point p1,p2;
        p1.x=0; p1.y=0; p2.x=100; p2.y=0;
        printf("%.8f %.8f\n",p1.x,p1.y);
        calc(0,p1,p2);
        printf("%.8f %.8f\n",p2.x,p2.y);

        return 0;
}

