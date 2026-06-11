#include<stdio.h>
int main()
{
    int power,i,j,k,temp,sum=0;
    scanf("%d%d",&power,&temp);
    for(i=0;i<temp;i++)
    {
        scanf("%d",&j);
        sum+=j;
    }
    if(sum>=power)
    {
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }

    return 0;
}
