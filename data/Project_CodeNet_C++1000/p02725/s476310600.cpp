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
    int k, n;
    cin>>k>>n;
    vi inp(n);
    for(auto& x: inp) cin>>x;
    sort(inp.begin(), inp.end());
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, inp[i] - inp[i-1]);
    ans = max(ans, k - inp[n-1] + inp[0]);
    cout<<k - ans;
    return 0;
}