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
    int k, q;
    cin >> k >> q;
    Vl d(k);
    for (int i = 0; i < k; i++) {
        scanf("%lld", &d[i]);
    }

    Vl m(q), x(q), n(q);
    for (int i = 0; i < q; i++) {
        scanf("%lld %lld %lld", &n[i], &x[i], &m[i]);
    }

    Vl dm(k);
    for (int i = 0; i < q; i++) {
        ll out = 0;
        for (int j = 0; j < k; j++) {
            dm[j] = d[j] % m[i];
        }
        for (int j = 0; j < k; j++) {
            if (dm[j] == 0) {
                if (j <= (n[i] - 1) % k - 1)
                    out += (n[i] - 1) / k + 1;
                else
                    out += (n[i] - 1) / k;
            }
        }
        ll a_last = x[i] % m[i];
        for (int j = 0; j < k; j++) {
            if (j <= (n[i] - 1) % k - 1)
                a_last += dm[j] * ((n[i] - 1) / k + 1);
            else
                a_last += dm[j] * ((n[i] - 1) / k);
        }
        out += a_last / m[i];
        printf("%lld\n", n[i] - 1 - out);
    }

    return 0;
}
