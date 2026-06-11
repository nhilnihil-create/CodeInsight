#include<stdio.h>
int main()
{
    int num,i,j,k,big=-1,avg,max,total=0,count[50];
    scanf("%d",&max);
     for(i=1;i<=max;i++)
    {
        if(i<=9)
            total++;
        else if(i>=100 && i<=999)
            total++;

        else if(i>=10000 && i<=99999)
            total++;
    }
    printf("%d",total);
    return 0;
}
