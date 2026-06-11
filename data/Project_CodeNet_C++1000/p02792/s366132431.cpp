#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;

    vector<vector<ll>> cnt(11, vector<ll>(11, 0));
    int order = 1;
    for (int i = 1; i <= N; ++i) {
        if (i / order >= 10) order *= 10;
        ++cnt[i / order][i % 10];
    }

    ll ans = 0;
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            ans += cnt[i][j] * cnt[j][i];
        }
    }
    cout << ans << endl;
}