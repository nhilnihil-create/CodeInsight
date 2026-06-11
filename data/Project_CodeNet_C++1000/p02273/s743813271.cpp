#include<iostream>
#include<cmath>
#include<cstdio>
#define PI 3.14159265358979
using namespace std;
struct P{
    double x,y;
};
int n;
int Koch(P p1,P p2,int counter){
    if(counter >= n) return 0;
    double th = 60.0*(PI/180.0); 
    P s,t,u;
    s.x = (2.0 * p1.x + 1.0 * p2.x)/3.0;
    s.y = (2.0 * p1.y + 1.0 * p2.y)/3.0;
    t.x = (1.0 * p1.x + 2.0 * p2.x)/3.0;
    t.y = (1.0 * p1.y + 2.0 * p2.y)/3.0;
    u.x = (t.x - s.x) * cos(th) - (t.y - s.y ) * sin(th) + s.x;
    u.y = (t.x - s.x) * sin(th) + (t.y - s.y ) * cos(th) + s.y;
    counter++;
    Koch(p1,s,counter);
    printf("%.8lf %.8lf\n",s.x,s.y);
    Koch(s,u,counter);
    printf("%.8lf %.8lf\n",u.x,u.y);
    Koch(u,t,counter);
    printf("%.8lf %.8lf\n",t.x,t.y);
    Koch(t,p2,counter);
}
int main(){
    const P first = {0.0,0.0},second = {100.0,0.0};
    cin >> n;
    printf("%.8lf %.8lf\n",first.x,first.y);
    Koch(first,second,0);
    printf("%.8lf %.8lf\n",second.x,second.y);
    return 0;
}
