#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    vector<ll> x,l;
    pair<ll,ll> arm[100000];
    for( int i = 0; i < n; i++ )
    {
        ll a,b;
        cin >> a >> b;
        arm[i].second = a - b;
        arm[i].first = a + b;
    }
    
    sort(arm,arm+n); 
    ll keep = -1000000000;
    ll ans = 0;
    for( int i = 0; i < n; ++i )
    {
        if( arm[i].second >= keep )
        {
            keep = arm[i].first;
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}

