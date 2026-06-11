#include <cstdio>
#include <algorithm>
int n,a[200003],b[200003],x,y;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x,&y);
        a[i]=x+y,b[i]=x-y;
    }
    std::sort(a+1,a+1+n),std::sort(b+1,b+1+n);
    printf("%d\n",std::max(a[n]-a[1],b[n]-b[1]));
    return 0;
}