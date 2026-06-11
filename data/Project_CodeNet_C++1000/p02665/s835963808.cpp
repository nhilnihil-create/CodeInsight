#include<bits/stdc++.h>

#define int unsigned long long

using namespace std;
int  n,ans=0;
int  a[100005],b[100005],c[100005];
signed  main()
{
    cin>>n;
    n++;
    for (int i=1; i<=n; i++)
        cin>>a[i];

    b[1]=1,c[n]=a[n];
    for (int i=2; i<=n; i++)
        b[i]=(b[i-1]-a[i-1])*2;
    for (int i=n-1; i>=1; i--)
        c[i]=c[i+1]+a[i];
    for (int i=1; i<=n; i++)
        ans+=min(b[i],c[i]);
    for (int i=1; i<=n; i++)
    {
        if (a[i]>b[i])
            return cout<<-1<<endl,0;
    }
    cout<<ans<<endl;

    return 0;
}
