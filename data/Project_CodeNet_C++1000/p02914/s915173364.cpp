#include<iostream>
#include<cstdio>
const int N=1e5+5;
typedef long long ll;
ll b[60],a[N];
void insert(ll x) {
    for(int i=59;~i;i--) if(x>>i&1) {
        if(!b[i]) {
            b[i]=x;
            break;
        }
        x^=b[i];
    }
}
int main() {
    ll sum=0;
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",a+i);
    ll ans=0;
    for(int j=0;j<60;j++) {
        int cnt=0;
        for(int i=1;i<=n;i++) cnt+=(a[i]>>j&1);
        if(cnt&1) {
            ans+=1LL<<j;
            for(int i=1;i<=n;i++) if(a[i]>>j&1) a[i]^=1LL<<j;
        }
    }
    for(int i=1;i<=n;i++) insert(a[i]);
    ll res=0;
    for(int i=59;~i;i--) if(b[i]) {
        if((res^b[i])>res) res^=b[i];
    }
    printf("%lld\n",ans+(res<<1));
    return 0;
}
