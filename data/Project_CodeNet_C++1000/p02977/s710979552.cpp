#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    if(__builtin_popcount(n)==1) {printf("No\n");return 0;}
    printf("Yes\n");
    if(n&1)
    {
        for(int i=1;i<3;i++)
            printf("%d %d\n",i,i+1);
        printf("%d %d\n",3,1+n);
        for(int i=1;i<3;i++)
            printf("%d %d\n",i+n,i+1+n);
        for(int i=4;i<=n;i+=2)
        {
            printf("%d %d\n",i,i+1);
            printf("%d %d\n",i+1,1);
            printf("%d %d\n",1,i+n);
            printf("%d %d\n",i+n,i+n+1);
        }
    }
    else
    {
        for(int i=1;i<3;i++)
            printf("%d %d\n",i,i+1);
        printf("%d %d\n",3,1+n);
        for(int i=1;i<3;i++)
            printf("%d %d\n",i+n,i+1+n);
        for(int i=4;i<n;i+=2)
        {
            printf("%d %d\n",i,i+1);
            printf("%d %d\n",i+1,1);
            printf("%d %d\n",1,i+n);
            printf("%d %d\n",i+n,i+n+1);
        }
        int x,y;
        for(int i=0;;i++)
        {
            if(1<<i&n)
            {
                x=1<<i;break;
            }
        }
        y=n^x^1;
        //cout<<"X:"<<x<<' '<<y<<endl;
        printf("%d %d\n",n,y);
        printf("%d %d\n",n+n,x==2?2:(x+n));
    }
}
