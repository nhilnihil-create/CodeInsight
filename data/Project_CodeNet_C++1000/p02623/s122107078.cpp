#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fast_I_O ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const int mod = 1e9+7 , INF = 1e9 ,  mx = 100005 ;
main()
{
    fast_I_O;
    int i,j,n,m,x,y,sum=0,p=0,l,k;
    cin>>n>>m>>k;
    int a[n+1],b[m+1];
    a[0] =0 , b[0]=0;
    for(i=1;i<=n;i++) cin>>a[i];
    for(i=1;i<=m;i++) cin>>b[i];

    for(i=1;i<=n;i++) a[i]=a[i-1]+a[i];
    for(i=1;i<=m;i++) b[i]=b[i-1]+b[i];

    //for(i=0;i<=n;i++) cout<<a[i]<<' ';
    //for(i=0;i<=m;i++) cout<<b[i]<<' ';

    for(i=0;i<=n;i++)
    {
        x=k-a[i];
        if(x<0) j=0;
        else j=i;
        y=upper_bound(b,b+m+1,x)-b;
        --y;
        p=max(j+y,p);
    }
    
    cout<<p;
    return 0;
}