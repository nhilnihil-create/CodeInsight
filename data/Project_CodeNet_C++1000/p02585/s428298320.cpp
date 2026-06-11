#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1<<30;
const ll LINF = 1LL<<60;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n, k; cin >> n >> k;
    vector<ll> p(n), c(n);
    for (int i = 0; i < n; i++) cin >> p[i], --p[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    ll ans = -LINF;

    for (int i = 0; i < n; i++) {
        int x = i;
        ll sum = 0, len = 0;

        while (true) {
            ++len;
            sum += c[x];
            x = p[x];
            if (x == i) break;
        }

        ll sum2 = 0, cnt = 0;

        while (true) {
            cnt++;
            sum2 += c[x];

            if (cnt > k) break;

            ll num = (k-cnt)/len;
            ll score = sum2 + max(0LL, sum)*num;
            ans = max(ans, score);

            x = p[x];
            if (x == i) break;
        }
    }

    cout << ans << endl;

    return 0;
}