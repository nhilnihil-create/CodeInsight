#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;

int main(){
    ll H, W, M; cin >> H >> W >> M;
    map<ll, ll> MH, MW;
    vector<pair<ll, ll>> V(M);
    for(int i = 0; i < M; i++){
        ll h, w; cin >> h >> w;
        MH[h]++;
        MW[w]++;
        V[i] = {h, w};
    }
    ll ans = 0;
    ll MAX1 = 0, MAX2 = 0;
    set<ll> VH, VW;
    for(auto p : MH) MAX1 = max(MAX1, p.second);
    for(auto p : MH) if(p.second == MAX1) VH.insert(p.first);

    for(auto p : MW) MAX2 = max(MAX2, p.second);
    for(auto p : MW) if(p.second == MAX2) VW.insert(p.first);

    ll cnt = 0, SIZE = VH.size()*VW.size();
    for(auto p : V){
        ll h = p.first, w = p.second;
        if(VH.find(h) != VH.end() && VW.find(w) != VW.end()) cnt++;
    }


    if(cnt == SIZE) cout << MAX1 + MAX2 -1 << endl;
    else cout << MAX1 + MAX2 << endl;
}