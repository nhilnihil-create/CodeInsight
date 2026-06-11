#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;

pair<int, ll> p[N];
ll a[N], cum[N];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n, dis, dam;
    cin >> n >> dis >> dam;
    for(int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
        a[i] = p[i].first;
    }
    sort(p, p + n);
    sort(a, a + n);
    ll ans = 0, sum = 0;
    for(int i = 0; i < n; i++){
        sum += cum[i];
        ll tmp = p[i].second - sum;
        if(tmp <= 0) continue;
        ll cost = tmp - tmp % dam;
        if(tmp % dam) cost += dam;
        sum += cost;
        ans += cost / dam;
        int idx = upper_bound(a, a + n, a[i] + 2 * dis) - a;
        cum[idx] -= cost;
        // update(1, 0, n - 1, 0, idx, cost);
    }
    cout << ans;

    return 0;
}
