#include<bits/stdc++.h>
using namespace std;
#define  mem(a,x) memset(a,x,sizeof(a));
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
int main()
{
    ft
    ll t,i,j,n,m,l,r;
    cin>>n>>m;
    ll a[n+1];
    r=1e9+7;
    mem(a,-1);
    a[0]=1;
    for(i=0;i<m;i++)
    {
        cin>>l;
        a[l]=0;
    }
    for(i=1;i<=n;i++)
    {
        if(a[i]==-1)
        {
            if(i-2>=0)
            {
                a[i]=a[i-1]+a[i-2];
            }
            else
            {
                a[i]=a[i-1];
            }
            a[i]%=r;
        }
    }
    cout<<a[n]<<"\n";
    return 0;
}