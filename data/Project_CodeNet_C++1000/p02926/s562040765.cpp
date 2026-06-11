#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105;
struct node{
    int x,y;
    bool operator<(const node&o)const{
        return atan2(y,x)<atan2(o.y,o.x);
    }
}a[N<<1];
int n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) a[i+n]=a[i];
    double ans=0;
    for(int i=1;i<=n;i++){
        ll x=0,y=0;
        for(int j=i;j<i+n;j++){
            x+=a[j].x;y+=a[j].y;
            ans=max(ans,sqrt(x*x+y*y));
        }
    }
    printf("%.15f\n",ans);
}
