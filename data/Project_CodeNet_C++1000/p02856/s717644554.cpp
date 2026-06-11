#include<iostream>
#include<cstdio>
const int N=2e5+5;
int n,d[N];
long long c[N];
int main() {
    scanf("%d",&n);
    long long ans=-1,sd=0;
    for(int i=1;i<=n;i++) {
        scanf("%d%lld",d+i,c+i);
        ans+=c[i];
        sd+=d[i]*c[i];
    }
    printf("%lld\n",ans+(sd-1)/9);
    return 0;
}
