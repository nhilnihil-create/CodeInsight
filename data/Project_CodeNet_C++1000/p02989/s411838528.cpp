#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
int main()
{
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    if(n%2 != 0)
    {
        cout<<0;
        return 0;
    }
    sort(arr,arr+n);
    cout<<max(0ll, arr[n/2] - arr[n/2 - 1]);
	return 0;
}