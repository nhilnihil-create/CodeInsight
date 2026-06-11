#include <iostream>
#include <math.h>
#include <string>
#include <string.h> 
#include <stdio.h>
using namespace std;
#define MAX 200000
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define OUT(n, m) printf("%lf %lf\n",n,m);
typedef struct Grid{
    double x,y;
}grid;
int koch(int d,grid r,grid l);
int main(){
    int n;
    
    grid p1={0,0},p2={100,0};
    scanf("%d",&n);
    OUT(p1.x,p1.y);
    koch(n,p1,p2);
    OUT(p2.x,p2.y);
}
int koch(int d,grid l,grid r){
    if(d==0)return 0;
    static const double pi = 3.141592653589793;
    grid s,t,u;
    s.x=(2*l.x + r.x)/3, s.y=(2*l.y + r.y)/3;
    t.x=(l.x + 2*r.x)/3, t.y=(l.y + 2*r.y)/3;
    u.x=(t.x-s.x)*cos(pi/3) - (t.y-s.y)*sin(pi/3)+s.x;
    u.y=(t.x-s.x)*sin(pi/3) + (t.y-s.y)*cos(pi/3)+s.y;
    koch(d-1,l,s);
    OUT(s.x,s.y);
    koch(d-1,s,u);
    OUT(u.x,u.y);    
    koch(d-1,u,t);
    OUT(t.x,t.y);
    koch(d-1,t,r);
    return 0;
}