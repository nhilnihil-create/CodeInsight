#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e13;

int main() {
    ll h, n;
    cin >> h >> n;

    vector<pair<ll, ll>> spell(n);
    for (int i = 0; i < n; i++)
        cin >> spell[i].first >> spell[i].second;

    vector<ll> damage(h+50, 0);
    for (int i = 1; i <= h; i++) {
        ll cost = INF;
        for (auto p : spell)
            if (p.first >= i && p.second < cost)
                cost = p.second;

        for (int j = 1; j < i; j++)
            cost = min(cost, damage[j] + damage[i-j]);

        damage[i] = cost;
    }

    cout << damage[h] << endl;
}