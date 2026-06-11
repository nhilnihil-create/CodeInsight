#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define sz 200009
ll n,m,i,j,k,l,t,arr[sz],brr[sz],crr[sz],drr[sz];
int main()
{
    ll mx=100000000000009;
    scanf("%lld",&n);
    if(n==0)
    {
        scanf("%lld",&m);
        printf("%lld\n",m==1?1ll:-1ll);
        return 0;
    }
    for(i=0;i<=n;i++){
        scanf("%lld",&arr[i]);
      if(arr[i]>m*2)
        l=1;
      else
      {
          if(i==0)
            m=1;
          else
          m=min(m*2,mx);
          brr[i]=m;
          m-=arr[i];
      }
    }
    if(l==1)
    {
        printf("-1\n");
        return 0;
    }
    m=0;
    for(i=n;i>=0;i--)
    {
        m+=arr[i];
        m=min(m,brr[i]);
        t+=m;
    }
    printf("%lld\n",t);
}
