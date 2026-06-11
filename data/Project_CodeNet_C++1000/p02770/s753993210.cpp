#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//==================================

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int k, q;
    cin >> k >> q;
    Vl d(k);
    for (int i = 0; i < k; i++) {
        cin >> d[i];
    }

    Vl dm(k);
    for (int i = 0; i < q; i++) {
        ll n, x, m;
        cin >> n >> x >> m;
        ll out = 0;
        ll a_last = x % m;
        for (int j = 0; j < k; j++) {
            dm[j] = d[j] % m;
        }
        for (int j = 0; j < k; j++) {
            ll tmp;
            if (j <= (n - 1) % k - 1)
                tmp = (n - 1) / k + 1;
            else
                tmp = (n - 1) / k;
            a_last += dm[j] * tmp;
            if (dm[j] == 0) out += tmp;
        }
        out += a_last / m;
        cout << n - 1 - out << "\n";
    }

    return 0;
}