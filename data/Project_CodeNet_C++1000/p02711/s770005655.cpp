#include <stdio.h>
int main()
{
    int n,c,d,e;
    scanf("%d",&n);
    c=n%10;
    d=(n%100)/10;
    e=n/100;
    if(c==7||d==7||e==7)
    {
        printf("Yes");
    }

    else{printf("No");}
    return 0;
}
