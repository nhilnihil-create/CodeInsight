#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define dbg(x) cout << #x << ": " << x << endl;
using namespace std;

const int N = 2e5 + 10, M = 1e6 + 10;
unordered_map<int, int> cnt;
unordered_map<int, int> vis;
int a[N];

void seive() {
    for (int i = 2; i <= 100; i++) {
        for (int j = i * i; j <= 100; j += i){
            if (!vis[j]) {
                vis[j] = 1;
            }
        }
    }
    rep(i, 2, 100) {
        if (!vis[i]) dbg(i);
    }
}
int main() {
    //seive();return 0;
    int n; cin >> n;
    int mx = 0;
    rep(i, 1, n) {
        cin >> a[i];
        vis[a[i]] = 1;
        //mx = max(mx, a[i]);
    }

    rep(i, 1, n) {
        int v = a[i];
        for (int j = 1; j * j <= v; j++) {
            if (v % j == 0) {
                cnt[v] += vis[j];
                if (j * j != a[i]) cnt[v] += vis[v / j];
            }
        }
    }
    int ans = 0;
    rep(i, 1, n) {
        if (cnt[a[i]] == 1) ans++;
    }
    cout << ans << endl;
}
