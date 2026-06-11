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
    ll a[n];
    ll freq[200001]={0};
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        freq[a[i]]++;
    }
    ll ans=0;
    for(i=0;i<200001;i++)
    {
        ans+=(freq[i]*(freq[i]-1))/2;
    }
    for(i=0;i<n;i++)
    {
        ll curr=ans+(1-freq[a[i]]);
        cout<<curr<<"\n";
    }
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