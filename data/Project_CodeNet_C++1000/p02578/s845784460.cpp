#include <cstdio>
int n,a[200003],max;
long long ans;//ans要开long long
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    max=a[1];//max初值为a[1]
    for(int i=2;i<=n;i++){
        if(max>a[i]) ans+=max-a[i];
        else max=a[i];
    }
    printf("%lld\n",ans);
    return 0;
}
