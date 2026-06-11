#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n, k;
    cin >> n >> k;
    int p[n];
    for (int i = 0; i < n; ++i) {
        cin >> p[i]; p[i]--;
    }
    ll c[n];
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    ll ans = -1e18;
    for (int st = 0; st < n; ++st) {
        ll rep = 0, cur = st;
        ll score = 0;
        while(true) {
            rep++;
            cur = p[cur];
            score += c[cur];
            if(cur == st) break;
        }
        if(k >= rep)
            ans = max(ans, k / rep * score);

        ll stp = 0;
        ll running = 0;
        while(true) {
            cur = p[cur];
            running += c[cur];
            stp++;
            if(k >= stp) {
                ans = max({ans, running, running + (k-stp)/rep * score});
            }
            if(cur == st) break;
        }
    }
    cout << ans << endl;
}
