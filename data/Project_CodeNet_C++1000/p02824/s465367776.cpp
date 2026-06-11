#include<bits/stdc++.h>
#define LL long long
#define int LL
using namespace std;
const int N=1e5+50;
int n,m,v,p,ans,q,a[N];LL s[N];
bool cmp(int x,int y){return x>y;}
signed main(){
    // freopen("test.in","r",stdin);
    scanf("%d%d%d%d",&n,&m,&v,&p);ans=p;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    for(int i=p+1;i<=n;i++){
        if(a[i]+m<a[p])continue;
        if(n-i+1+p-1>=v){ans++;continue;}
        int num=i-p;LL sum=s[i-1]-s[p-1];
        if(num*(a[i]+m)-sum>=m*(v-(n-num)))ans++;
    }
    printf("%d\n",ans);
}