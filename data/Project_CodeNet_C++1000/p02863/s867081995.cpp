#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MN = 3e3 + 5;
int N, T;
int dp[2 * MN];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    cin >> N >> T;
    vector<pii> v;
    for (int i = 1; i <= N; i++) {
        int a, b; cin >> a >> b;
        v.emplace_back(a, b);
    }
    sort(all(v));
    for (int i = 1; i <= N; i++) {
        int a = v[i - 1].first, b = v[i - 1].second;
        for (int j = T - 1; j >= 0; j--) {
            dp[j + a] = max(dp[j + a], dp[j] + b);
        }
    }
    cout << *max_element(dp, dp + 2 * MN) << '\n';
    return 0;
}