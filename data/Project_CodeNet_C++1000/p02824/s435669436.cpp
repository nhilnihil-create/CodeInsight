#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using piii = pair<int, pair<int, int>>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 1e9 + 7;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M, V, P;
    cin >> N >> M >> V >> P;
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    sort(A.begin(), A.end());

    vector<ll> Asum(N + 1);
    for (int i = 0; i < N; ++i)
        Asum[i + 1] = Asum[i] + A[i];

    int ans = P;
    P = N - P;
    for (int i = 0; i < P; ++i) {
        ll tmp = A[i] + M;
        auto itr = upper_bound(A.begin(), A.end(), tmp);
        if (itr - A.begin() <= P)
            continue;
        ll cost = (i + N - P - 1) * M;
        cost += (P + 1 - i) * tmp - (Asum[P + 1] - Asum[i]);
        if (cost >= M * V)
            ans++;
    }

    cout << ans << endl;
    return 0;
}
