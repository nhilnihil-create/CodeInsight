#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll n;
    cin >> n;
    vector<pair<ll,ll>> xy(n);
    for(ll i = 0;i < n;i++){
        cin >> xy[i].first >> xy[i].second;
    }
    sort(xy.begin(),xy.end());

    ll ans = n, cnt = 0;
    for(ll i = 0;i < n;i++){
        for(ll j = i + 1;j < n;j++){
            ll mx = 0;
            ll tp = xy[i].first - xy[j].first;
            ll tq = xy[i].second - xy[j].second;
            for(ll k = 0;k < n;k++){
                for(ll l = k + 1;l < n;l++){
                    if(xy[k].first - xy[l].first == tp && xy[k].second - xy[l].second == tq){
                        mx++;
                        break;
                    }
                }
            }
            cnt = max(cnt,mx);
        }
    }
    
    ans = n - cnt;

    cout << ans;

    return 0;
}
