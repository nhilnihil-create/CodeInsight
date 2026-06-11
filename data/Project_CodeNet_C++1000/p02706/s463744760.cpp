#include<stdio.h>

int main()
{
    int n,m,d=0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        int x;
        scanf("%d",&x);
        d += x;
    }
    if(n>=d)
        printf("%d\n",n-d);
    else
        printf("-1\n");
    return 0;
}

