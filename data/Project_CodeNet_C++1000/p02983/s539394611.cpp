#include<bits/stdc++.h>
 
#define rep(i,n) for(ll i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;
 
const int INF = 1001001001;
const long double PI = (acos(-1));
const int mod = 1e9+7;
const int vx[6] = {0,1,0,-1,1,-1};
const int vy[6] = {1,0,-1,0,1,1};




int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll l,r;
    cin >> l >> r;
    int MOD = 2019;
    ll ans = INF * 2;
    for(ll i = l;i <= r-1;++i){
        for(ll j = i+1;j <= r;++j){
            ans = min(ans,((i%MOD)*(j%MOD))%MOD);
            if(ans == 0) break;
        }
        if(ans == 0) break;
    }
    cout << ans << endl;
    cout << endl;
    return 0;
}
