#include<stdio.h>
int main()
{
    int num,i,j,k,big=-1,avg,max,total=0,count[50];
    scanf("%d",&max);
    for(i=0;i<max;i++)
    {
        scanf("%d",&count[i]);
    }
    for(i=1;i<max-1;i++)
    {
        if(count[i]>count[i-1] && count[i]<count[i+1])
        {
            total++;
        }
        else if(count[i]<count[i-1] && count[i]>count[i+1])
        {
            total++;
        }
    }
    printf("%d",total);
    return 0;
}
