#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,i,k;
    scanf("%d %d",&a,&b);
    if(a>b)
    {
        for(i=0;i<a;i++)
        {
            printf("%d",b);
        }
    }
    else
    {
        for(i=0;i<b;i++)
        {
            printf("%d",a);
        }
    }
    printf("\n");
    return 0;
}