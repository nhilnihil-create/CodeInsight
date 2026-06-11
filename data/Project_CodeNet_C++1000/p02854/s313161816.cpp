#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main()
{
    int n;
    cin>>n;
    ll a[n];
    ll sum =0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum += a[i];
    }
    ll curr =0;
    ll ans =LLONG_MAX;
    for(int i=0;i<n;i++)
    {
        curr += a[i];
        ans = min( ans , abs(sum - 2*curr ) );
    }
    cout<<ans;
}