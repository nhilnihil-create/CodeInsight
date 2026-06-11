#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ll long long
#define ll_MAX LONG_LONG_MAX
#define ll_MIN LONG_LONG_MIN
#define pi pair<int,int>
#define endl "\n"
#define MAXN 100005
#define mod 1000000007
using namespace std;

void solve()
{
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cout.tie(NULL);
    solve();
    ll n;
    cin>>n;
    vector<ll> spf(n + 1, 0);
    spf[1] = 1;
    for(ll i=2; i<=n; i+=2)
    {
        spf[i] = 2;
    }
    for(ll i=3; i<=n; i+=2)
    {
        if(spf[i] == 0)
        {
            spf[i] = i;
            for(ll j=i*2; j<=n; j+=i)
            {
                if(spf[j] == 0)
                {
                    spf[j] = i;
                }
            }
        }
    }
    ll ans = 1;
    for(ll i=2; i<=n; i++)
    {
        ll t = i;
        ll val = 1;
        while(t > 1)
        {
            ll p = spf[t];
            ll cnt = 0;
            while(t%p == 0)
            {
                t = t/p;
                cnt++;
            }
            val = val*(cnt+1);
        }
        ans = ans + i*val;
    }
    cout<<ans<<'\n';
}