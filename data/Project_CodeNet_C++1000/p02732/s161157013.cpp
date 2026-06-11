#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<ll> cnt(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i] - 1]++;
    }
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        if (cnt[i] == 0) continue;
        sum += cnt[i] * (cnt[i] - 1) / 2;
    }
    for (int i = 0; i < n; i++) {
        cout << sum - (cnt[a[i] - 1] - 1) << endl;
    }
    return 0;
}