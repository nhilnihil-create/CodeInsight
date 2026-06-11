#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include <bitset>
#include <numeric>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[8]={ 0, 1, 0,-1, 1, 1,-1,-1}; // x軸方向への変位
ll dy[8]={ 1, 0,-1, 0, 1,-1, 1,-1}; // y軸方向への変位

int main(void) {
    ll a, b, m;
    cin >> a >> b >> m;
    ll x[a], y[b];
    map<p, ll> I{};
    for(ll i = 0; i < a; i++)
        cin >> x[i];
    for(ll i = 0; i < b; i++)
        cin >> y[i];
    ll ans = 1e+9;
    for(ll i = 0; i < m; i++){
        ll c, d, e;
        cin >> c >> d >> e;
        ans = min(ans, x[c-1]+y[d-1]-e);
    }
    sort(x, x+a);
    sort(y, y+b);
    ans = min(ans, x[0]+y[0]);
    cout << ans << endl;
    return 0;
}
