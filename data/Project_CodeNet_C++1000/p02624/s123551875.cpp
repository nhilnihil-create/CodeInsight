#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<ll> cnt(N + 1, 1);
    for (int i = 2; i <= N; ++i) {
        for (int j = i; j <= N; j += i) {
            ++cnt[j];
        }
    }

    ll ans = 0;
    for (ll i = 1; i <= N; ++i) {
        ans += i * cnt[i];
    }

    cout << ans << endl;
}