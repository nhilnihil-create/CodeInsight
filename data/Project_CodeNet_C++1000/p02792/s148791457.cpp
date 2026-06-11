#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N;

// 先頭と最後の桁を見つける
P f(ll x) {
    string tmp = to_string(x);

    return P(tmp[0], tmp[tmp.size() - 1]);
}
int main() {
    cin >> N;

    map<P, int> mp;
    for (ll i = 1; i <= N; i++) {
        P p = f(i);
        mp[P(p.first, p.second)]++;
    }

    int ans = 0;
    for (ll i = 1; i <= N; i++) {
        P p = f(i);
        ans += mp[P(p.second, p.first)];
    }

    cout << ans << endl;
}