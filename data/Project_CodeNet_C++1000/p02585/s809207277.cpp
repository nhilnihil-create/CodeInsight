#include <iostream>
#include <vector>
#include <string>


using namespace std;
using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;

    vector<ll> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    vector<ll> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    ll ans = -1e+18;
    for (int i = 0; i < n; i++) {
        ll v = p[i] - 1;
        ll l = 1;
        ll c_sum = c[i];
        while (v != i) {
            l++;
            c_sum += c[v];
            v = p[v] - 1;
        }
        if (c_sum < 0) c_sum = 0;

        v = p[i] - 1;
        ll sum = 0;
        for (int i = 0; i < l; i++) {
            if (i >= k) break;
            sum += c[v];
            ans = max(ans, c_sum * ((k - i - 1) / l) + sum);
            v = p[v] - 1;
        }
    }

    cout << ans << endl;
}
