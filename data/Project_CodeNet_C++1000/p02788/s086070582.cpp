// 5/13 過去問ガリガリ
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using Graph = vector<vector<int>>;

const ll INF = 1000000009;

int main() {
    ll N;  // モンスターの数
    ll D;  // 爆弾の距離
    ll A;  // 爆弾の威力
    cin >> N >> D >> A;

    // vector<ll> X(N), H(N);
    vector<pair<ll, ll>> Monster(N);
    rep(i, N) {
        ll x, h;
        cin >> x >> h;
        Monster[i] = make_pair(x, h);
    }

    sort(Monster.begin(), Monster.end());

    // 以下は自力実装。いくつかのデータでTLE。

    // vector<ll> max_j(N);
    // vector<ll> damage_sum(N, 0);

    // rep(i, N) {
    //     auto it = upper_bound(Monster.begin(), Monster.end(), make_pair(Monster[i].first + 2 * D, INF));

    //     // cout << it - Monster.begin() - 1 << endl;
    //     max_j[i] = it - Monster.begin() - 1;
    // }

    // ll ans = 0;

    // rep(i, N) {
    //     ll hitpoint_left = Monster[i].second - damage_sum[i];

    //     if (hitpoint_left > 0) {
    //         ll attack_num = hitpoint_left / A;
    //         if (hitpoint_left % A != 0) attack_num += 1;

    //         for (int k = i; k <= max_j[i]; k++) {
    //             damage_sum[k] += A * attack_num;
    //         }

    //         ans += attack_num;
    //     }
    // }

    // 以下は解説動画のsnukeさんの実装

    ll tot = 0;  // その時点のトータルダメージ
    queue<pair<ll, ll>> q;
    ll ans = 0;

    rep(i, N) {
        ll x = Monster[i].first;
        ll h = Monster[i].second;        

        while (q.size() && q.front().first < x) {
            tot -= q.front().second;
            q.pop();
        }

        h -= tot;

        if (h > 0) {
            ll num = (h + A - 1) / A;
            tot += num * A;
            q.emplace(make_pair(x + 2 * D, num * A));
            ans += num;
        }
    }

    cout << ans << endl;
}
