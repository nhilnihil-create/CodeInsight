#include<bits/stdc++.h>
#define ll long long int
#define ff first
#define ss second
#define eps 1e-9

using namespace std;


int main()
{

    ll t,n,m,f,l,r,q,k,x,y,z,ans,mn,mx,sum=0;

    cin>>n;

    vector< ll > a(n+1),b(n+1),c(n);

    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }

    for(int i=1; i<=n; i++)
    {
        cin>>b[i];
    }

    for(int i=1; i<n; i++)
    {
        cin>>c[i];
    }
    l = -10;
    ans=0;
    for(int i=1;i<=n;i++)
    {
        mn = a[i];

        if(mn-1 == l)
        {
            ans+= b[mn] + c[mn-1];
        }
        else
        {
            ans+= b[mn];
        }

        l = a[i];
    }

    cout<<ans<<endl;


}
