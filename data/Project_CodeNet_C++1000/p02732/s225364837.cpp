#include<bits/stdc++.h>
using namespace std;

#define IOS             ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define watch(x);       cout << "\n" <<  #x << " is: " << x << "\n";
#define ll              long long int
#define ff              first
#define ss              second
#define all(a)          a.begin(),a.end()
#define pb              push_back
#define nl              cout<<"\n"
#define gcd(a,b)        __gcd(a,b)
#define sq(a)           (a)*(a)
#define loop(i,a,b)     for (ll i = a; i <= b; i++)
#define rloop(i,a,b)    for (int i = a; i >= b; i--)
#define sz(a)           a.size()
#define mod             1000000007
#define PI              2*acos(0.0)

int main()
{
    IOS
    int T=1;
    //cin>>T;
    while(T--)
    {
        ll n;
        cin>>n;
        ll a[n];
        map<ll,ll>mp;

        loop(i,0,n-1)
        {
            cin>>a[i];
            mp[a[i]]++;
        }
        ll ans=0;
        for(ll i=1;i<=n;i++)
             if(mp[i]>0) ans+=mp[i]*(mp[i]-1)/2;
        loop(i,0,n-1)
        {
            ll p=mp[a[i]];
            ll x=((p-1)*(p-2)/2)-(p*(p-1)/2);
            cout<<ans+x;
            nl;
        }

    }
    return 0;
}
