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

    Vl m(q), x(q), n(q);
    for (int i = 0; i < q; i++) {
        cin >> n[i] >> x[i] >> m[i];
    }

    Vl dm(k);
    Vl coeffs(k);
    for (int i = 0; i < q; i++) {
        ll out = 0;
        ll a_last = x[i] % m[i];
        for (int j = 0; j < k; j++) {
            dm[j] = d[j] % m[i];
        }
        for (int j = 0; j < k; j++) {
            if (j <= (n[i] - 1) % k - 1)
                coeffs[j] = (n[i] - 1) / k + 1;
            else
                coeffs[j] = (n[i] - 1) / k;
        }
        for (int j = 0; j < k; j++) {
            if (dm[j] == 0) out += coeffs[j];
            a_last += dm[j] * coeffs[j];
        }
        out += a_last / m[i];
        cout << n[i] - 1 - out << "\n";
    }

    return 0;
}
