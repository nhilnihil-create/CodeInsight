#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (long long)((a).size())
const double pi = 3.14159265358979323846;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

    ll n,i,j;
    cin>>n;
    ll ans = 0;
    for(i=1;i<=n;i++) ans+=(i*(n-i+1));
    ll u,v;
    for(i=0;i<n-1;i++)
    {
        cin>>u>>v;
        ll mn = min(u,v);
        ll mx = max(u,v);
        ans-=(mn*(n-mx+1));
    }
    cout<<ans;
}