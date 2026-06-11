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

    ll N, M, V, P;
    cin >> N >> M >> V >> P;
    Vl A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end(), greater<ll>());

    Vl csum(N + 1);
    for (int i = 0; i < N; i++) {
        csum[i + 1] = csum[i] + A[i];
    }

    int idx;
    for (idx = 0; idx < N; idx++) {
        if (idx < P) continue;
        if (A[idx] + M < A[P - 1]) {
            break;
        }
        ll r = max(V - (N - idx) - (P - 1), 0LL);
        ll s = idx - P + 1;
        ll cs = csum[idx] - csum[P - 1];
        if ((A[idx] + M) * s - cs < r * M) {
            break;
        }
    }

    cout << idx << endl;

    return 0;
}