#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ll n , m  , k, x;
    vector<ll>v1 , v2;
    cin >> n >> m >> k;
    for(ll i = 0 ; i < n ;i++)
    {
        cin >> x;
        if(i==0)
            v1.push_back(x);
        else
        {
            v1.push_back(v1[i-1]+x);
        }
    }
    ll ans=0;
    for(ll i = 0 ; i < m ;i++)
    {
        cin >> x;
        if(i==0)
            v2.push_back(x);
        else
        {
            v2.push_back(v2[i-1]+x);
        }
        x=upper_bound(v1.begin(),v1.end(), k-v2[i] )-v1.begin()-1;
        if(v2[i]<=k)
        {
            ans=max(ans , x+1+i+1 );
        }
        else break;
    }
    for(ll i = 0 ; i < n ;i++)
    {
        x=upper_bound(v2.begin(),v2.end(), k-v1[i] )-v2.begin()-1;
        if(v1[i]<=k)
        {
            ans=max(ans , x+1+i+1 );
        }
        else break;
    }
    cout << ans ;
    return 0;
}
