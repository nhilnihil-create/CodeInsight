#include<cstdio>
int n;
int main(){
    scanf("%d",&n);
    if(n==1<<(31-__builtin_clz(n)))return puts("No"),0;
    puts("Yes");
    printf("%d %d\n%d 3\n3 1\n1 2\n2 %d\n",1+n,2+n,2+n,3+n);
    for(int i=4;i+1<=n;i+=2)
    printf("%d %d\n%d 1\n1 %d\n%d %d\n",i+n,i+1,i+1,i,i,i+1+n);
    if(n%2==0){
        int x=__builtin_ctz(n);
        printf("%d %d\n%d %d\n",n,1<<x,n^1^(1<<x),2*n);
    }
    return 0;
}