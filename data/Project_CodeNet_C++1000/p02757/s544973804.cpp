#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
// typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N, P;
string S;

map<ll, ll> mp;

int main() {
    cin >> N >> P >> S;

    reverse(S.begin(), S.end());

    if (10 % P == 0) {
        ll ans = 0;
        // 2の倍数
        // 末尾が偶数

        // 5の倍数
        // 末尾が 0 or 5
        for (int i = 0; i < N; i++) {
            if ((S[i] - '0') % P == 0) {
                ans += (N - i);
            }
        }
        cout << ans << endl;
        return 0;
    }

    // まず P と 10が素であるとする
    // cout << S << endl;
    // vector<ll> sum(N + 1);
    // sum[0] = 0;

    // rep(i, S.size()) {
    //     sum[i + 1] += sum[i] + (S[i] - '0');        
    //     sum[i + 1] %= P;
    // }

    // rep(i, sum.size()) {
    //     // cout << sum[i] << endl;
    //     mp[sum[i]]++;
    // }
    mp[0] = 1;
    ll ten = 1;
    ll num = 0;
    rep(i, N) {
        ll target = S[i] - '0';
        num += target * ten;
        num %= P;

        mp[num]++;
        ten *= 10;
        ten %= P;
    }

    ll ans = 0;
    for (auto m : mp) {
        // cout << m.first << " " << m.second << endl;
        ll tmp = m.second * (m.second - 1) / 2;
        // cout << tmp << endl;
        ans += tmp;
    }

    cout << ans << endl;
}