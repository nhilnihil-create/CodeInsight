#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    ll ans = a[0];
    if (N % 2) {
        for (int i = 0; i < N / 2 - 1; i++) {
            ans += 2 * a[i + 1];
        }
        ans += a[N / 2];
    } else {
        for (int i = 0; i < N / 2 - 1; i++) {
            ans += 2 * a[i + 1];
        }
    }
    cout << ans << endl;
    return 0;
}
