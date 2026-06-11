#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
ll const INF = 1LL << 60;
ll const MAX_N = 510000;
ll const MOD = 1000000007;

int main() {
    string S;
    ll K;
    cin >> S >> K;

    vector<int> cnt;
    int small_cnt = 1;
    for (int i = 1; i < S.length(); i++) {
        if (S[i - 1] == S[i]) {
            small_cnt++;
        } else {
            cnt.push_back(small_cnt);
            small_cnt = 1;
        }
    }
    cnt.push_back(small_cnt);

    // repv(cnt) cout << *it << " ";
    // cout << endl;

    if (cnt.size() == 1) {
        cout << S.length() * K / 2 << endl;
        return 0;
    }

    ll ans = 0;
    repv(cnt) { ans += (*it / 2) * K; }

    // cout << ans << endl;

    if (S[0] == S[S.length() - 1]) {
        ans -= (cnt[0] / 2) * (K - 1);
        // cout << "b :" << ans << endl;
        ans -= (cnt[cnt.size() - 1] / 2) * (K - 1);
        // cout << "e :" << ans << endl;
        ans += (cnt[0] + cnt[cnt.size() - 1]) / 2 * (K - 1);
    }

    cout << ans << endl;

    return 0;
}