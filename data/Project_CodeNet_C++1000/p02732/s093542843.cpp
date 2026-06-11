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
    //io;
    int n;
    cin>>n;
    vll cnt(n+1), contri(n+1), inp(n);
    for(int i =0 ;i < n;i++)
    {
        cin>>inp[i];
        cnt[inp[i]]++;
    }
    ll tot = 0;
    for(int i = 0; i<= n; i++)
    {
        contri[i] = cnt[i]*(cnt[i] - 1)/2;
        tot += contri[i];
    }

    for(int i =0 ;i < n; i++)
    {
        ll ans = tot - contri[inp[i]] + (cnt[inp[i]] - 1)*(cnt[inp[i]] - 2)/2;
        cout<<ans<<"\n";
    }
    return 0;
}