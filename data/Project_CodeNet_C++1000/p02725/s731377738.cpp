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
    ll p;
    cin>>p;
    cin>>n;
    ll a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    ll ans=p;
    // if(n==2)
    // {
    //     ll g=abs(a[0]-a[1]);
    //     g=min(g,p-g);
    //     cout<<g;
    //     return;
    // }
    for(i=0;i<n-1;i++)
    {
        ll x=a[i];
        ll y=a[i+1];
        ans=min(ans,p-(abs(x-y)));
    }
    ll g=p-a[n-1];
    ans=min(ans,p-(a[0]+g));
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