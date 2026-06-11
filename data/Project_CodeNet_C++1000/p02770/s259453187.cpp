#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define MAX 500002
int main()
{
    int k,i,j,q;
    scanf("%d %d",&k,&q);
    int d[k];
    long long int temp[k+1];
    for(i=0;i<k;i++)
    {
        scanf("%d",&d[i]);
    }
    for(j=0;j<q;j++)
    {
        int n,x,m;
        scanf("%d %d %d",&n,&x,&m);
        temp[0]=x%m;
        int rem=(n-1)%k;
        int zrem=0,total=0;
        int division=(n-1)/k;
        for(i=1;i<=k;i++)
        {
            temp[i]=d[i-1]%m;
            if(temp[i]==0)
            {
                total++;
                zrem=zrem+(i<=rem);
            }
            temp[i]=temp[i]+temp[i-1];
        }
        long long int ans=total;
        ans=ans*division;
        ans=ans+zrem;
        long long int dd=(temp[k]-temp[0])*division+temp[rem];
        dd=dd/m;
        ans=ans+dd;
        ans=n-1-ans;
        printf("%lld\n",ans);
    }
    return 0;
}
