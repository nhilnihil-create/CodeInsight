#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")



int main() {

    ll n,m; cin >> n >> m;
    ll a,b,ans = 0;

    vector<pair<ll,bool>> h(n);

    rep(i,n){
        cin >> h[i].first;
        h[i].second = true;
    }

    rep(i,m){
        cin >> a >> b;
        a --; b --;
        if(h[a].first == h[b].first) {
            h[a].second = false;
            h[b].second = false;
        }else
        if(h[a].first > h[b].first) h[b].second = false;
        else h[a].second = false;
    }

    rep(i,n){
        if(h[i].second) ans ++;
    }

    cout << ans;

    return 0;
}
