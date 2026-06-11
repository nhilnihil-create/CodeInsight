#include <bits/stdc++.h>

#define EPS (1e-10)
#define rep(i, a, b) for (int i = a; i < (int)(b); ++i)
#define rrep(i, a, b) for (int i = b - 1; i >= (int)(a); --i)
#define all(a) a.begin(), a.end()

using namespace std;
using ll = long long;
using vi = vector<int>;
using vb = vector<bool>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvb = vector<vb>;

constexpr int MOD = 1000000007;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s, t;
    cin >> s >> t;

    // O(nlog(n))
    map<char, vi> sdict;
    rep(i, 0, 26) { sdict[char(i + 'a')] = vi(); }
    rep(i, 0, s.size()) {
        sdict[s[i]].push_back(i);
        sdict[s[i]].push_back(i + s.size());
    }

    rep(i, 0, 26) { sort(all(sdict[char(i + 'a')])); }

    ll ans = 0;
    int pos = 0;

    for (char c : t) {
        // s内に文字が無ければ終了．
        if (sdict[c].empty()) {
            cout << -1 << endl;
            return 0;
        }

        // pos以降で最も近く一致する文字を探す．
        int next_pos = *upper_bound(sdict[c].begin(), sdict[c].end(), pos - 1);

        // 文字数をカウント．
        ans += next_pos - pos + 1;

        // posを更新．
        pos = (next_pos + 1) % s.size();
    }

    cout << ans << endl;
    return 0;
}