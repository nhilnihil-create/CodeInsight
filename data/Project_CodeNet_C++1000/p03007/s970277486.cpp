#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
using ll = long long;

int N;
vector<ll> A;

void solve() {
    vector<ll> plus, minus;
    for (int i = 0; i < N; ++i) {
        if (A[i] >= 0) plus.push_back(A[i]);
        else minus.push_back(A[i]);
    }
    sort(plus.begin(), plus.end(), greater<ll>());
    sort(minus.begin(), minus.end());
    if (minus.empty()) minus.push_back(plus.back()), plus.pop_back();
    if (plus.empty()) plus.push_back(minus.back()), minus.pop_back();

    vector<pair<ll, ll>> res;
    ll cur = minus[0];
    for (int i = 0; i + 1 < plus.size(); ++i) {
        res.push_back({cur, plus[i]});
        cur -= plus[i];
    }
    res.push_back({plus.back(), cur});
    cur = plus.back() - cur;

    for (int i = 1; i < minus.size(); ++i) {
        res.push_back({cur, minus[i]});
        cur -= minus[i];
    }

    cout << cur << endl;
    for (auto p : res) cout << p.first << " " << p.second << endl;
}

int main() {
    cin >> N;
    A.resize(N);
    rep(i, N) cin >> A[i];
    solve();
}