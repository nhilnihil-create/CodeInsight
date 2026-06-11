#include<bits/stdc++.h>
#define ll long long
#define pb push_back
long long int mod = (long long int)1000000007;
using namespace std;

void solve()
{
    ll i,j,k,n;
    std::cout.precision(10);
    int yes=0;
    cin>>n;
    map<ll,ll>mp1;
    ll a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        mp1[i-a[i]]++;
    }
    ll ans=0;
    for(i=0;i<n;i++)
    {
        ans+=mp1[a[i]+i];
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int i,j,k;
    int t;
    std::cout.precision(10);
    t=1;
    while(t--)
    {
        solve();
        cout<<"\n";
    }
}