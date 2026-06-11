#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<lint>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const lint INF = 1LL << 60;
const int MAX = 1000000;

int n;
lint k;
vec a, f;

bool isOK(lint mid) {
    lint diff = 0;

    rep(i, n) {
        diff += max(0LL, a[i] - mid/f[i]);
    }

    return diff <= k;
}

lint binary_search() {
    lint left = -1;
    lint right = 1000000000010;

    while (right - left > 1) {
        auto mid = left + (right - left) / 2;

        if (isOK(mid)) right = mid;
        else left = mid;
    }

    /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
    return right;
}

int main() {
    cin >> n >> k;
    a.resize(n);
    f.resize(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> f[i];

    sort(all(a));
    sort(all(f), greater<lint>());

    lint res = binary_search();

    cout << res << endl;
    return 0;
}