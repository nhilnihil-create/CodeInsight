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
#define mod   1000000007
#define PI 2*acos(0.0)
#define dbg(a) cout<<#a<<" ->->->-> "<<a<<"\n"
#define N 200005
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
    int n, a, b;
    cin>>n>>a>>b;

    //dbg(n);

    vi fac(N);
    fac[0] = 1;
    for(int i = 1; i< N; i++)
        fac[i] = 1LL*fac[i-1]*i %mod;

    ll numa = 1, numb = 1;

    for(int i = n; i > n - a; i--)
        numa = (numa * i)%mod;

    for(int i = n; i>n-b; i--)
        numb = (numb * i)%mod;

    //dbg(fac[N-1]);

    ll c = (bigmod(2, n) - 1 + mod)%mod;

    //dbg(c);

    ll d = (numa* bigmod(fac[a], mod - 2))%mod;

    //dbg(d);

    d = ((numb * bigmod(fac[b], mod - 2))%mod + d)%mod;
    //dbg(d);

    cout<<(c - d + mod)%mod;
    return 0;
}