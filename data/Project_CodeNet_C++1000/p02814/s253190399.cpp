#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define hell 1000000007
#define PI 3.14159265358979323846
using namespace std;
ll hcf(ll a,ll b)
{
    if(a%b==0)
        return b;
    else
        return hcf(b,a%b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;

   // cin>>t;
    while(t--)
    {
       ll n,m,i;
       cin>>n>>m;
       ll arr[n+1];
       for(i=0;i<n;i++)
        cin>>arr[i];
       ll p=arr[0];
       for(i=1;i<n;i++)
       {
           ll h=hcf(p,arr[i]);
           ll l=p*arr[i]/h;
           p=l;
       }
       for(i=0;i<n;i++)
       {
           if((p/arr[i])%2==0)
            break;
       }
       if(i<n || p>2*m)
        cout<<0;
       else
       {
           ll ans=2*m/p;
           cout<<(ans+1)/2;
       }
    }
}
