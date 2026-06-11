#include<stdio.h>
int main()
{
    int n,p;
    while(~scanf("%d%d",&n,&p)&&(n+p))
    {
        int a[150]={0},ans,flag=0,ball=p;
        while(1)
        {
            for(int i=0;i<n;i++)
            {
                if(ball)
                    a[i]++,ball--;
                else
                    ball+=a[i],a[i]=0;
                if(a[i]==p)
                {
                    ans=i;
                    flag=1;
                    break;
                }
            }
            if(flag)
                break;
        }
        printf("%d\n",ans);
    }
    return 0;
}

