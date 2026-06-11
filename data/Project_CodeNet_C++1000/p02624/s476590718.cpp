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
        cin >> n;
        vector<ll> v(n+1,1);

        for (ll i = 2; i <= n; i++)
        {
            for (ll j = i; j <= n; j+=i) v[j]++;
        }
        ll ans = 0;
        for (ll i = 1; i <= n; i++)
        {
            ans += (i)*v[i];
        }
        cout << ans ;

    }
    return 0;
}
