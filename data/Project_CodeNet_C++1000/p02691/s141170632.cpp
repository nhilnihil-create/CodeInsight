#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
int main()
{
    ll n;
    cin >> n;
    vector <ll> arr(n);
    vector<ll>plus;
    vector<ll>minus;
    for(ll i=0;i<n;i++)
    {
        cin >> arr[i];
        plus.push_back(arr[i]+i);
        minus.push_back((i-arr[i]));
    }
    ll ans=0;
    sort(minus.begin(),minus.end());
    for(ll i=0;i<plus.size();i++)
    {
        ll coins;
        coins=plus[i];
       ll upper=upper_bound(minus.begin(),minus.end(),coins)-minus.begin() ;
       ll lower=lower_bound(minus.begin(),minus.end(),coins)-minus.begin() ;
        ans+=upper-lower;
    }
    cout << ans<<"\n";

}
