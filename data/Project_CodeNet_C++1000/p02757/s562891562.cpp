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
//#define mod   1000000000
#define PI 2*acos(0.0)
#define dbg(a) cout<<#a<<" ->->->-> "<<a<<"\n"
int dirx[] = {1, -1,0, 0}, diry[] = {0, 0, 1, -1};

ll bigmod(ll x, ll p, int mod)
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
    string s;
    int n, p;
    cin>>n>>p>>s;
    if(p == 2 || p == 5)
    {
        ll ans = 0;
        for(int i =0 ; i< n;i++)
            if((s[i] - '0')%p == 0)
                ans += i+1;
        cout<<ans;
        return 0;
    }
    vi cnt(p), modul;
    int am = 0;
    for(int i =0 ; i< n; i++)
    {
        am = (am * 10%p + (s[i] - '0')%p)%p;
        modul.pb(am);
    }

    for(int i = 0; i< n; i++)
        cnt[modul[i]*bigmod(10, n-1-i, p)%p]++;

    cnt[0]++;
    ll ans = 0;
    for(auto x: cnt)
        if(x >= 2)
            ans += 1LL*x*(x-1)/2;
    cout<<ans;
    return 0;
}

