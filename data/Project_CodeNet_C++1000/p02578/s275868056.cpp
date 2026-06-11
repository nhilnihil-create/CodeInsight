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
    ll a[n];
    for (ll i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    ll stools = 0;
    for(ll i=1; i<n; i++)
    {
        // cout<<stools<<'\n';
        if(a[i] < a[i - 1])
        {
            stools += a[i-1] - a[i];
            a[i] = a[i-1];
        }
    }
    cout<<stools<<'\n';
}