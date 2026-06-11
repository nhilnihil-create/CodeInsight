#include<stdio.h>
int main()
{
    int num,i,j=1,k,big=-1,avg,max,total=0,count[50];
    scanf("%d",&max);
    for(i=0; i<max; i++)
    {
        scanf("%d",&count[i]);
        if(count[i]!=j)
        {
            total++;
        }
        j++;

    }
    if(total>2)
    {
        printf("NO");
    }
    else
    {
        printf("YES");
    }
    return 0;
}