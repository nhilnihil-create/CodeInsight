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
    ll n;
    cin>>n;
    if(n == 2)
        return cout<<1, 0;
    int ans = 2;
    for(ll i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            ll ac = n;
            while(ac%i == 0)
                ac /= i;
            if(ac%i == 1)
                ans++;
            if(n/i != i)
            {
                ac = n;
                ll is = n/i;
                while(ac%is == 0)
                    ac/= is;
                if(ac%is == 1)
                    ans++;
            }
        }
    }

    n--;

    for(ll i = 2; i*i <= n; i++)
    {
        if(n%i == 0)
        {
            ans++;
            if(n/i != i)
                ans++;
        }
    }

    cout<<ans;
    return 0;
}

