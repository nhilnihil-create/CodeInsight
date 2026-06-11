#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;

    vector<pair<ll, ll>> apple;
    ll tmp;
    rep(i, A) {
        cin >> tmp;
        apple.push_back(make_pair(tmp, 0));
    }
    rep(i, B) {
        cin >> tmp;
        apple.push_back(make_pair(tmp, 1));
    }
    rep(i, C) {
        cin >> tmp;
        apple.push_back(make_pair(tmp, 2));
    }

    sort(apple.begin(), apple.end(), greater<>());

    ll ans = 0;
    vector<int> MAX = {X, Y, 10000000};
    vector<int> cnt(3, 0);
    rep(i, A + B + C) {
        pair<ll, ll> p = apple[i];
        if (cnt[p.second] >= MAX[p.second]) continue;
        ++cnt[p.second];
        ans += p.first;

        if (cnt[0] + cnt[1] + cnt[2] == X + Y) break;
    }

    cout << ans << endl;
}