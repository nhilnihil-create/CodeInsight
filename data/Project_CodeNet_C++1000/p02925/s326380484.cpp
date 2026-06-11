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
    ll n;
    cin >> n;

    vector<vector<ll>> a(n, vector<ll>(n-1));
    rep(i, n)rep(j, n-1){
        cin >> a[i][j];
        a[i][j]--;
    }

    ll ans = 0;
    while(true){
        bool isok = false;
        bool used[n] = {};
        rep(i, n){
            if(used[i] || a[i].empty())continue;
            
            ll cmp = a[i][0];
            if(a[cmp].empty()){
                isok = false;
                break;
            }

            if(i == a[cmp][0] && !used[cmp]){
                isok = true;

                used[i] = true;
                used[cmp] = true;

                a[i].erase(a[i].begin());
                a[cmp].erase(a[cmp].begin());
            }
        }

        if(!isok)break;

        ans++;
    }

    bool ispossible = true;
    rep(i, n)if(!a[i].empty()){
        ispossible = false;
        break;
    }

    if(ispossible)cout << ans << endl;
    else cout << -1 << endl;
}