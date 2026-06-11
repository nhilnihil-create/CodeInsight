#include <cstdio>
#include <algorithm>
bool cmp(int x,int y){return x>y;}
int n,a[200003],p;
long long ans;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    std::sort(a+1,a+1+n,cmp);
    ans=a[1],p=2;
    for(int i=3;i<=n;i++){
        ans+=a[p];
        if(!(i&1)) ++p;
    }
    printf("%lld\n",ans);
    return 0;
}