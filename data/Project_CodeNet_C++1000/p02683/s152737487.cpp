#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;
const ll MOD = 1000000007;
const ll MX = 0; //最大値

#define rep(i,n) for(ll i=0; i<(ll)(n); i++)
#define ALL(x) (x).begin(),(x).end()
#define MAX(x) *max_element(ALL(x))
#define PB push_back
#define F first
#define S second

int main(){
    ll n, m, x; cin >> n >> m >> x;
    ll ans = INF;
    vector<ll> C(n);
    vector<vector<ll>> A(n, vector<ll>(m));
    rep(i, n) {
        cin >> C[i];
        rep(j, m) cin >> A[i][j];
    }

    for (ll i = 0; i < (1 << n); i++){
        vector<ll> R(n);
        ll cnt = 0;
        rep(j, n){
            if((i>>j)&1){
                cnt += C[j];
                rep(k, m){
                    R[k] += A[j][k];
                }
            }
        }

        bool ok = true;
        rep(j, m){
            if(R[j] < x) ok = false;    
        }
        if(ok) ans = min(ans, cnt);
    }
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}