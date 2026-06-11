#include <bits/stdc++.h>
#define rep(i, a, n) for(ll i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    map<ll, int> mp;
    rep(i, 1, 1000000){
        mp[i*i] = 1;
    }
    ll n, d;
    cin >> n >> d;
    vector<vector<ll>> x(n, vector<ll> (d));
    rep(i, 0, n) rep(j, 0, d) cin >> x[i][j];
    ll ans = 0;
    rep(i, 0, n-1) rep(j, i+1, n){
        ll dist = 0;
        rep(k, 0, d){
            dist += pow((x[i][k] - x[j][k]), 2);
        }
        if(mp[dist]) ans++;
    }
    cout << ans << endl;
    return 0;
}
