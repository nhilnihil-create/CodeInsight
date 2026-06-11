#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
int main()
{
    ll n;
    cin>>n;
    vector<ll> v(n);
    ll sum=0;
    for(ll i=0;i<n;i++)
        cin>>v[i],sum+=v[i];
    
    ll x[n];
    ll sum2{};
    for(ll i=1;i<n;i+=2)
        sum2 += v[i];
    x[0] = sum - 2*sum2;
    for(ll i=0;i<n-1;i++)
    {
        x[i+1] = 2*v[i] - x[i];
    }
    for(ll i=0;i<n;i++)
        cout<<x[i]<<" ";
	return 0;
}