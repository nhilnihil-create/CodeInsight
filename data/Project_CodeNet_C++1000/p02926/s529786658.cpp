#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=1e2+10;
struct point{
    int x,y;
}p[maxn];
bool cmp(point a,point b){
    return atan2(a.y,a.x)<atan2(b.y,b.x);
}
int nx[maxn];
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>p[i].x>>p[i].y;
    for(int i=1;i<=n;i++)nx[i]=i+1; nx[n]=1;
    sort(p+1,p+n+1,cmp);
    ll ans=0;
    for(int i=1;i<=n;i++){
        ll x=p[i].x,y=p[i].y;
        ans=max(ans,x*x+y*y);
        for(int j=nx[i];j!=i;j=nx[j]){
            x+=p[j].x;
            y+=p[j].y;
            ans=max(ans,x*x+y*y);
        }
    }
    cout<<setiosflags(ios::fixed)<<setprecision(10)<<sqrt(ans);
    return 0;
}
