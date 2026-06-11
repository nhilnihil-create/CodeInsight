#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
#define pll pair<ll, ll>

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<pll> P(N);

    rep(i, N) {
        ll a, b;
        cin >> a >> b;
        P[i] = {a, b};
    }

    sort(all(P), [](pll a, pll b) { return a.second < b.second; });

    ll time = 0;
    rep(i, N) {
        time += P[i].first;
        if (time > P[i].second) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;
}