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
    string s,t;
    cin>>s>>t;
    ll n = s.size();
    ll k = t.size();
    ll ans = 10000;
    for(ll i=0; (i + k)<=n; i++)
    {
        ll diff = 0;
        ll p = 0;
        for(ll j=i; j<(i + k); j++)
        {
            if(s[j] != t[p])
                diff++;
            p++;
        }
        // cout<<diff<<'\n';
        ans = min(ans, diff);
    }
    cout<<ans<<'\n';
}