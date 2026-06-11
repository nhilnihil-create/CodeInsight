#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define Speed ios_base::sync_with_stdio(false); cin.tie(NULL)

int main()
{
    ll n;
    cin>>n;
    vector<ll> A;
    map<ll,ll> mp;
    for(ll i=0;i<n;i++)
    {
        ll c;cin>>c;
        A.push_back(c);
    }

    for(ll i=0;i<n;i++)
    {
        mp[A[i]]=i+1;
    }

    sort(A.begin(),A.end());

    for(auto x: A)
    {
        cout<<mp[x]<<" ";
    }
}