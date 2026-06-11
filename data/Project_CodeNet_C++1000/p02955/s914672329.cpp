#include <bits/stdc++.h>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep(i, n) repd(i, 0, n)

using namespace std;

using ll = long long;
using ul = unsigned long long;
using ld = long double;
ll mod = 1000000007;

bool solve(vector<ll> &v, ll num, ll k) {
    ll n = v.size();
    vector<ll> m_array(n);
    rep(i, n) { m_array[i] = v[i] % num; }
    sort(m_array.begin(), m_array.end());

    vector<ll> l_sum(n), r_sum(n);
    l_sum[0] = m_array[0];
    repd(i, 1, n) { l_sum[i] = l_sum[i - 1] + m_array[i]; }
    r_sum[n - 1] = num - m_array[n - 1];
    repb(i, n - 1) { r_sum[i] = r_sum[i + 1] + (num - m_array[i]); }
    if (l_sum[n - 1] <= k || r_sum[0] <= k) {
        return true;
    }

    ll k_min = mod;
    rep(i, n - 1) { k_min = min(k_min, max(l_sum[i], r_sum[i + 1])); }

    /*
    cout << "num: " << num << endl;
    rep(i, n) { cout << l_sum[i] << " "; }
    cout << endl;
    rep(i, n) { cout << r_sum[i] << " "; }
    cout << endl;

    cout << "k_min: " << k_min << endl;
    cout << endl;
    */

    return k_min <= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i, n) { cin >> a[i]; }

    ll sum = 0;
    rep(i, n) { sum += a[i]; }

    vector<ll> div;
    for (ll i = 1; i * i <= sum; i++) {
        ;
        if (sum % i == 0) {
            div.push_back(i);
            div.push_back(sum / i);
        }
    }

    ll ans = 0;
    sort(div.begin(), div.end());

    for (auto d : div) {
        if (solve(a, d, k)) {
            ans = d;
        }
    }

    cout << ans << endl;

    return 0;
}

