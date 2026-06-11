//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll n,x,i,ans=0;
    cin>>n;
    ll a[n-1];
    for(i=0; i<n-1; i++)
        cin>>a[i];
    ans=a[0];
    for(i=1; i<n-1; i++)
    {
        ans+=min(a[i-1],a[i]);
    }
    ans+=a[n-2];
    cout<<ans<<endl;



    return 0;
}



