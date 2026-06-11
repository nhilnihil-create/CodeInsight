#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const int N=2e5+10;
struct point{
    int x,h;LL p;
}a[N];
bool cmp(point x,point y){
    return x.x<y.x;
}
int n,d,A;
LL ans;
int main(){
    scanf("%d%d%d",&n,&d,&A);
    d*=2;
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].x,&a[i].h);
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        a[i].p+=a[i-1].p;
        a[i].h-=a[i].p*A;
        if(a[i].h<=0)continue;
        int times=(a[i].h+A-1)/A;
        a[i].p+=times;ans+=times;
        int L=i,R=n,p,now=a[i].x+d;
        while(L<=R){
            int mid=(L+R)>>1;
            if(a[mid].x<=now){
                p=mid;L=mid+1;
            }
            else R=mid-1;
        }
        a[p+1].p-=times;
    }
    cout<<ans<<endl;
}