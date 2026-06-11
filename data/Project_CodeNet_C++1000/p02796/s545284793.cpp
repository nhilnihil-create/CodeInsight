#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vll x(n), l(n);
    rep(i, n) cin >> x[i] >> l[i];

    vector<pair<ll, ll>> p(n);
    rep(i, n) {
        p[i].second = x[i] - l[i];
        p[i].first = x[i] + l[i];
    }

    sort(p.begin(), p.end());

    ll t = p[0].first;
    ll cnt = 1;
    for (int i = 1; i < n; i++) {
        if (t <= p[i].second) {
            cnt++;
            t = p[i].first;
        }
    }

    cout << cnt << endl;
}