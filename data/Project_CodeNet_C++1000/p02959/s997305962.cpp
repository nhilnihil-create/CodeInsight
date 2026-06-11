#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
   ll a[n+1],b[n];
   for(int i=0;i<n+1;i++)
    cin>>a[i];
   for(int i=0;i<n;i++)
    cin>>b[i];

    ll ans=0;
    for(int i=0;i<n;i++)
    {
        if(b[i]>a[i])
        {
            ans+=a[i];
            b[i]-=a[i];
            ll tm=min(a[i+1],b[i]);
            ans+=tm;
            a[i+1]-=tm;
        }
        else
        {
            ans+= b[i];
        }
    }
    cout<<ans;

}
