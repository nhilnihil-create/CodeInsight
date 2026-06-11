#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n+1];
    for(int i=0;i<=n;++i) cin>>a[i];
    if(n==0)
    {
        if(a[0]==1)
        {
            cout<<1;
            return 0;
        }
        else
        {
            cout<<(-1);
            return 0;
        }
    }
    int b[n+1];
    b[0]=1;
    for(int i=0;i<n;++i)
    {
        b[i+1]=min(2*(b[i]-a[i]),(int) 1e18);
    }
    int c[n+1];
    c[n]=a[n];
    if(b[n]<a[n])
    {
        cout<<(-1);
        return 0;
    }
    for(int i=(n-1);i>=0;i--)
    {
        c[i]=c[i+1]+a[i];
    }
    int res[n+1];
    int sum=0;
    for(int i=0;i<=n;++i)
    {
        res[i]=min(b[i],c[i]);
        sum+=res[i];
        if(res[i]<=0)
        {
            cout<<(-1);
            return 0;
        }
    }
    cout<<sum;
    return 0;
}
