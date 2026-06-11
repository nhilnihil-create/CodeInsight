#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0, i##_len = (int)(n); i < i##_len; i++)
#define rep1(i, n) for (int i = 1, i##_len = (int)(n); i <= i##_len; i++)
#define rrep(i, n) for (int i = (int)(n)-1; 0 <= i; i--)
#define rrep1(i, n) for (int i = (int)(n); 1 <= i; i--)

#define each(it, c) \
    for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define all(obj) (obj).begin(), (obj).end()

#define pcount __builtin_popcount
#define SZ(x) ((int)(x).size())
#define LEN(x) ((int)(x).length())

#define dump(x) cerr << #x << " = " << (x) << endl;

#define endl "\n"

template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

typedef long long lint;

using namespace std;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, n;
    cin >> h >> n;
    map<int, int> magic;
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        if (!magic.count(a))
            magic[a] = b;
        else if (b < magic[a])
            magic[a] = b;
    }
    vector<lint> dp(int(1e8), LLONG_MAX);
    dp[0] = 0;
    rep(i, h) {
        if (dp[i] != LLONG_MAX)
            for (const auto &e : magic) {
                chmin(dp[i + e.first], dp[i] + e.second);
            }
    }
    lint ans = LLONG_MAX;
    for (int i = h; i < int(1e8); i++) chmin(ans, dp[i]);
    cout << ans << endl;
}