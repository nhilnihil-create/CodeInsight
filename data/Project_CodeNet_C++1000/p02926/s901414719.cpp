#include<bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
struct node{
    double x,y,v;
}a[105];
bool cmp(node a,node b){
    return a.v<b.v;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
        a[i].v=atan2(a[i].x,a[i].y);
    }
    sort(a+1,a+1+n,cmp);
    double res=0;
    for(int i=1;i<=n;i++){
        double x=a[i].x,y=a[i].y;
        res=max(res,sqrt(x*x+y*y));
        for(int j=i%n+1;j!=i;j=j%n+1){
            x+=a[j].x,y+=a[j].y;
            res=max(res,sqrt(x*x+y*y));
        }
    }
    printf("%.70lf",res);
}