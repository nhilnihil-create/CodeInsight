#include<stdio.h>
int main() {
    int n,g,i,j,t,k,res,ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        scanf("%d",&res);
        if(i%2==1 && res%2==1) ans++;
    }
    printf("%d\n",ans);
    return 0;
}
