/*BISMILLAH
THE WHITE WOLF
NO DREAM IS TOO BIG AND NO DREAMER IS TOO SMALL*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<long long> vll;
typedef vector<int> vi;

#define io ios_base::sync_with_stdio(false)
#define pb push_back
#define eb emplace_back
#define mod   998244353
#define PI 2*acos(0.0)
#define dbg(a) cout<<#a<<" ->->->-> "<<a<<"\n"
int dirx[] = {1, -1,0, 0}, diry[] = {0, 0, 1, -1};

ll bigmod(ll x, ll p)
{
    ll res = 1;
    while(p)
    {
        if(p&1)
            res = (res*x)%mod;
        x = (x*x)%mod;
        p >>= 1;
    }
    return res;
}

//=============================================ASIFAZAD==============================================//


int32_t main()
{
    io;
    int x, y, a, b, c;
    cin>>x>>y>>a>>b>>c;
    vi ia(a), ib(b), ic(c);

    for(auto& x: ia) cin>>x;
    for(auto& x: ib) cin>>x;
    for(auto& x: ic) cin>>x;

    sort(ia.begin(), ia.end(), greater<int>());
    sort(ib.rbegin(), ib.rend());

    for(int i= 0; i< min(a, x); i++)
        ic.pb(ia[i]);

    for(int i =0 ; i< min(y, b); i++)
        ic.pb(ib[i]);

    sort(ic.rbegin(), ic.rend());
    ll ans =0 ;
    for(int i =0 ; i< x+y; i++)
        ans += ic[i];
    cout<<ans;
    return 0;
}