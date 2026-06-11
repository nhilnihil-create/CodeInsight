#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
const int w=3e5+5;
const ll mod=1e9+7;
int a[w],b[w];
int main()
{
    int i,j;
    int k,q;
    cin>>k>>q;
    for(i=0;i<k;i++)
        scanf("%lld",&a[i]);
    while(q--)
    {
        int n,x,m;
        scanf("%d %d %d",&n,&x,&m);
        ll s=0;
        for(i=0;i<k;i++)
        {
            b[i]=a[i]%m;
            if(b[i]==0)
                b[i]=m;
            s+=b[i];
        }
        ll ans=x+s*((n-1)/k);
        for(i=0;i<(n-1)%k;i++)
            ans+=b[i];
        printf("%lld\n",n-1-(ans/m-x/m));
    }
    return 0;
}
