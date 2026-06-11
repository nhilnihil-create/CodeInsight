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
#define loop(i,a,b)     for (int i = a; i <= b; i++)
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
        loop(i,0,n-1) cin>>a[i];
        sort(a,a+n);
        loop(i,0,n-2) a[i]*=2;
        ll x=(n-2)/2;
        ll ans=a[n-1];
        ll i=0;
        while(x>0)
        {
            ans+=a[n-i-2];
            i++;
            x--;
        }
        if(n&1) ans+=(a[n-i-2]/2);
        cout<<ans;

    }
    return 0;
}
