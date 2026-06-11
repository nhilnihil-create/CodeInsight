#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
#define eps 1e-8
const int maxn=2e5+10;
int sgn(double k) {return k<-eps?-1:(k<eps?0:1);}
struct point{
    double x,y,theta;
    point(double a=0,double b=0,double c=0) {x=a,y=b,theta=c;}
    friend bool operator<(const point &a,const point &b) {
        return a.theta<b.theta;
    }
}p[2*maxn];
int n;
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lf %lf",&p[i].x,&p[i].y),p[i].theta=atan2(p[i].y,p[i].x);
    sort(p+1,p+n+1);
    for(int i=1;i<=n;i++) p[n+i]=point(p[i].x,p[i].y,p[i].theta+2*pi);
    int point_=0;
    double sumx=0,sumy=0,ans=0;
    for(int i=1;i<=n;i++) {
        while(sgn(p[point_+1].theta-p[i].theta-pi)<=0) {
            sumx+=p[++point_].x,sumy+=p[point_].y;
            ans=max(ans,sumx*sumx+sumy*sumy);
        }
        sumx-=p[i].x,sumy-=p[i].y;
        ans=max(ans,sumx*sumx+sumy*sumy);
    }
    printf("%.10lf\n",sqrt((double)ans));
}