#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const ll MOD = 1e9 + 7;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

ll comb(ll n, ll r) {
    ll ret = 1;
    for (ll i = 0; i < r; i++) ret = ret * (n - i);
    for (ll i = 1; i <= r; i++) ret /= i;
    return ret;
}

int main(){
    ll n,l,r; cin >> n;
    vector<vector<ll>> c(9,vector<ll>(9,0));
    ll ans = 0;

    for(int i = 1; i <= n; i ++){
        r = i%10;
        l = i;
        while(l/10 != 0){
            l /= 10;
        }
        if(l != 0 && r != 0)c[l-1][r-1] ++;
    }

    rep(i,9){
        rep(j,9) ans += c[i][j]*c[j][i];
    }

    cout << ans;

}