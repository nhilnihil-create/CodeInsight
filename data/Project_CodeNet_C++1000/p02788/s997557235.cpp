#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(void){
    int N;
    ll D, A;
    cin >> N >> D >> A;
    vector<pair<ll, ll>> XH(N);
    for(int i = 0; i < N; i++) cin >> XH[i].first >> XH[i].second;
    sort(XH.begin(), XH.end());
    ll ans = 0;
    vector<ll> damage(N + 1, 0);
    for(int tgt = 0; tgt < N; tgt++){
        if(tgt >= 1) damage[tgt] += damage[tgt - 1];
        XH[tgt].second -= damage[tgt];
        if(XH[tgt].second <= 0) continue;
        ll left = XH[tgt].first;
        ll right = left + 2 * D;
        auto ritr = upper_bound(XH.begin(), XH.end(), make_pair(right, 1LL << 32LL));
        int rpos = distance(XH.begin(), ritr);
        ll nb = (XH[tgt].second + A - 1) / A;
        ans += nb;
        damage[tgt] += A * nb;
        damage[rpos] -= A * nb;
    }
    cout << ans << endl;
}
