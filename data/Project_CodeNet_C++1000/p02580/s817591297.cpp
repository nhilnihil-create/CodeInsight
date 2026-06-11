#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(pos,mp) for(ll pos=mp.begin();pos!=mp.end();pos -++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

int main(){
    ll h, w, m;
    cin >> h >> w >> m;

    vector<ll> bomh(h, 0);
    vector<ll> bomw(w, 0);

    map<pll, ll> mp;

    rep(i, m){
        ll bh, bw;
        cin >> bh >> bw;
        bh--, bw--;

        mp[make_pair(bh, bw)] = 1;

        bomh[bh]++;
        bomw[bw]++;
    }

    vector<ll> ordh(h), ordw(w);
    iota(ALL(ordh), 0);
    iota(ALL(ordw), 0);
    sort(ALL(ordh), [&](ll x, ll y){
        return bomh[x] > bomh[y];
    });
    sort(ALL(ordw), [&](ll x, ll y){
        return bomw[x] > bomw[y];
    });

    ll ans = bomh[ordh[0]] + bomw[ordw[0]] - 1;
    rep(i, h){
        if(bomh[ordh[i]] != bomh[ordh[0]])break;
        rep(j, w){
            if(bomw[ordw[j]] != bomw[ordw[0]])break;
            if(mp.count(make_pair(ordh[i], ordw[j])) == 0){
                cout << ans + 1;
                return 0;
            }
        }        
    }

    cout << ans << endl;
}