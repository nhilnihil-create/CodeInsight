#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, k;
    cin >> n >> k;
    ll p[n], c[n];
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        p[i]--;
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    ll ans = -1e18;
    for (int st = 0; st < n; ++st) {
        int running = p[st];
        ll cycscore = c[running], cyclen = 1;
        while(running != st) {
            running = p[running];
            cycscore += c[running];
            cyclen++;
        }

        ll runningscore = 0;
        for(int r = 1; r <= n; r++) {
            running = p[running];
            runningscore += c[running];
            if(r <= k) {
                ans = max(ans, runningscore);
                if(cycscore > 0) ans = max(ans, runningscore + (k - r) / cyclen * cycscore);
            }
        }
    }
    cout << ans << endl;
}
