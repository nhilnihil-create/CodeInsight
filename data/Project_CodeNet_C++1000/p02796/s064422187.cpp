#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

ll N, ans=0, tmp=0;
vector<pair<ll, ll>> XL;

void solve(){
    ll cur = -10000000000;
    for(int i=0;i<N;i++) {
        if(cur<=XL[i].second) {
            ans++;
            cur = XL[i].first;
        }
    }
}

signed main(){
    cin >> N;
    for(int i=0;i<N;i++) {
        ll x, l;
        cin >> x >> l;
        XL.push_back({x+l, x-l});
    }
    sort(XL.begin(), XL.end());
    solve();
    cout << ans << endl;
    return 0;
}