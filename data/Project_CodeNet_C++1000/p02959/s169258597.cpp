#include<bits/stdc++.h>
#define ll long long int
#define ff first
#define ss second
#define eps 1e-9

using namespace std;


int main()
{

    ll t,n,m,f,a,b,c,l,r,q,k,x,y,z,ans,mn,mx,sum=0;

    cin>>n;


    vector< ll > arr(n+1),hr(n);

    for(int i=0; i<=n; i++)
    {
        cin>>arr[i];
    }

    for(int i=0; i<n; i++)
    {
        cin>>hr[i];
    }
    ans=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]<hr[i])
        {
            ans+= arr[i];
            hr[i]-=arr[i];

            mn = min(hr[i],arr[i+1]);
            ans+= mn;
            arr[i+1]-=mn;
        }
        else
        {
            ans+= hr[i];
        }

    }
    cout<<ans<<endl;
}
