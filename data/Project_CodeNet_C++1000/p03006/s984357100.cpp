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

    ll ans = n, cnt = 0;
    for(ll i = 0;i < n;i++){
        for(ll j = 0;j < n;j++){
            if(i == j)continue;
            ll mx = 0;
            ll tp = xy[i].first - xy[j].first;
            ll tq = xy[i].second - xy[j].second;
            for(ll k = 0;k < n;k++){
                for(ll l = 0;l < n;l++){
                    if(k == l)continue;
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