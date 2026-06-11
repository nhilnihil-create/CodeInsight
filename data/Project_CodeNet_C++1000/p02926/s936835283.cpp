#include<bits/stdc++.h>
using namespace std;
const int N=200;
struct node{
    double x,y;
}e[N];
bool cmp(const node &a,const node &b){//极角排序
    return atan2(a.y,a.x)<atan2(b.y,b.x);
}
int n;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>e[i].x>>e[i].y;
    sort(e,e+n,cmp);
    double ans=0;
    for(int i=0;i<n;i++){
        double x=e[i].x,y=e[i].y;
        ans=max(ans,x*x+y*y);
        for(int j=(i+1)%n;j!=i;j=(j+1)%n){
            x+=e[j].x,y+=e[j].y;
            ans=max(ans,x*x+y*y);
        }
    }
    printf("%.20f\n",sqrt(ans));
}
