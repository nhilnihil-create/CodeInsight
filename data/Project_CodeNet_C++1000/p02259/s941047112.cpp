#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,count=0;
    scanf("%d",&t);
    int a[t];

    for(int i=0; i<t; i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0; i<t-1; i++)
    {
        for(int j=0; j<t-i-1; j++)
        {
            if(a[j]>a[j+1])
            {
                a[j]=a[j]+a[j+1];
                a[j+1]=a[j]-a[j+1];
                a[j]=a[j]-a[j+1];
                count++;
            }
        }
    }
    for(int i=0; i<t; i++)
    {
        printf("%d",a[i]);
        if(i<t-1)
            printf(" ");

    }
    cout<<endl;
    printf("%d\n",count);
    return 0;
}

