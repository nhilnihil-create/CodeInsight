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
    ll a,b;
    cin>>n>>a>>b;
    if(a==0 && b==0)
    {
        cout<<"0";
        return;
    }
    ll x=n/(a+b);
    ll y=n%(a+b);
    ll ans=x*a +min(a,y);
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