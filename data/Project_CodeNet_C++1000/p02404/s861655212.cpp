#include <stdio.h>

int main()
{
    int a,b;
    int c,d;
    while(1){
    scanf("%d %d",&a,&b);
    if(a==0 && b==0) return 0;
    for(c=1;c<=a;c++)
    {
        if(c==1 || c==a)
        {
            for(d=1;d<=b;d++)
            {
                printf("#");
                if(d==b) printf("\n");
            }
        }else{
        for(d=1;d<=b;d++)
        {
            if(d==1 || d==b)
            {
                printf("#");
            }else{
            printf(".");
            }
            if(d==b) printf("\n");
        }
        }
    }
    printf("\n");
    }
    return 0;
}