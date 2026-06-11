#include<cstdio>

int main(){
    int a[44],n;
    a[0]=a[1]=1;
    for(int i=2;i<=44;i++) a[i]=a[i-1]+a[i-2];
    scanf("%d",&n);
    printf("%d\n",a[n]);
    return 0;
}