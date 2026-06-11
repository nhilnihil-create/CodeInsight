#include <bits/stdc++.h>


using namespace std;


using ll = long long;


int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> member(N, 0);
    vector<ll> foods(N, 0);

    for (ll i = 0; i < N; i++) {
        cin >> member[i];
    }
    for (ll i = 0; i < N; i++) {
        cin >> foods[i];
    }

    sort(member.begin(), member.end());
    sort(foods.rbegin(), foods.rend());

    ll l = -1, r = 1200000000000LL;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        ll diff = 0;
        for (ll i = 0; i < N; i++) {
            diff += max(0LL, member[i] - (m / foods[i]));
        }
        if (diff <= K) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << endl;
}
