#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>


using namespace std;
typedef long long ll;

int main() {
    while(true) {
        ll n, m; cin >> n >> m;
        if (n == 0 && m == 0) break;
        vector<pair<ll, ll>> roads;
        for(ll i = 0; i < n; i++) {
            int d, p; cin >> d >> p;
            roads.push_back({d, p});
        }
        sort(roads.begin(), roads.end(), [](pair<ll, ll> a, pair<ll, ll> b){ return a.second > b.second;});
        ll b = 0;
        for (ll i = 0; i < n; i++) {
            if (roads[i].first < m) {
                m -= roads[i].first;
                roads[i].first = 0;
            } else {
                roads[i].first -= m;
                m = 0;
                b = i;
                break;
            }
        }
        ll ans = 0;
        for (ll i = b; i < n; i++) {
            ans += roads[i].first*roads[i].second;
        }
    cout << ans << endl;
    }
}
