#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,x,n,r=0;
    scanf("%d", &x);
    for(i=x;i>=x;i++)
    {
        r=0;
        if(i==2)
        {
           break;
        }
        else
        {
            for(j=2;j*j<=i;j++)
        {
            if(i%j==0)
            {
                r=0;
                break;
            }
            else
                r=1;

        }
        }
        if(r==1)
            break;
    }
    printf("%d\n", i);
    return 0;
}
