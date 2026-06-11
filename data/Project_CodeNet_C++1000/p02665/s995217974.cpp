#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define ll long long 
const int maxn=1000010;
ll a[maxn];
ll amin[maxn],amax[maxn];
ll pow2[maxn];
ll ans; int n;
int main(){
    scanf("%d",&n);
    for (int i=0;i<=n;++i){
        scanf("%lld",&a[i]);
    }
    pow2[0]=1;
    for (int i=1;i<=n&&pow2[i-1]<=100000000;++i){
        pow2[i]=pow2[i-1]<<1;
    }
    amax[n]=amin[n]=a[n];
    bool flag=true;
    for (int i=n-1;i>=0;--i){
        amin[i]=(amin[i+1]+1)/2+a[i];
        amax[i]=amax[i+1]+a[i];
        if (pow2[i]) amax[i]=min(amax[i],pow2[i]);
        if (amin[i]>pow2[i]&&pow2[i]){
            flag=false; break;
        }
    }
    if (!flag){
        printf("-1"); return 0;
    }
    if (!n&&a[0]>1){
        printf("-1"); return 0;
    }
    ans=amax[0];
    for (int i=1;i<=n;++i){
        amax[i]=min(amax[i],(amax[i-1]-a[i-1])*2);
        amin[i]=max(amin[i],(amin[i-1]-a[i-1]));
        if (amax[i]<amin[i]){
            flag=false; break;
        }
        ans+=amax[i];
    }
    if (!flag) printf("-1");
    else printf("%lld",ans);
    return 0;
}