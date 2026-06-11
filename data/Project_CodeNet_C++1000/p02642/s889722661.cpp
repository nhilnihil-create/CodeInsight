#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> has(1000001), cnt(1000001);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ++has[a[i]];
    }
    for (int i = 1; i <= 1000000; i++) if (has[i]) {
        for (int j = i + i; j <= 1000000; j += i) {
            ++cnt[j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (cnt[a[i]] == 0 && has[a[i]] == 1) {
            ++ans;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    run();
    return 0;
}
