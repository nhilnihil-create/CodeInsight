#include <bits/stdc++.h>
long long int m,n,z,ans;
using namespace std;
long long int vp[200010],sum;
map<long long int,long long int>q;
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&vp[i]);
        vp[i]+=vp[i-1]-1;
    }
    for(int i=1;i<=n;i++)
        vp[i]%=k;
    q[0]++;
    for(int i=1;i<=n;i++)
    {
        if(i>=k)
            q[vp[i-k]]--;
sum+=q[vp[i]];
        q[vp[i]]++;

    }
    printf("%lld",sum);
}