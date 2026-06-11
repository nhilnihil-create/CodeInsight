#include <cstdio>
#define abs(x) ((x)<0?-(x):(x))
int main(){
    long long x,k,d,y;scanf("%lld%lld%lld",&x,&k,&d);
    y=abs(x)/d;
    if(k<=y) printf("%lld\n",abs(x)-k*d);
    else{
        long long now=abs(x)-d*y;
        if(k-y&1ll) printf("%lld\n",abs(now-d));
        else printf("%lld\n",now);
    }
    return 0;
}