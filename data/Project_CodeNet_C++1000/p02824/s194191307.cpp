#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

bool isOk(ll N, ll M, ll V, ll P, vector<ll>& A, int x) {
    if (x < P)
        return true;

    ll maxP = A[x] + M;
    if (maxP < A[P - 1])
        return false;

    ll res = M * V;
    res -= (P - 1) * M;
    res -= (N - x) * M;
    for (int i = P - 1; i < x; i++) {
        res -= min(max(0ll, maxP - A[i]), M);
    }

    return res <= 0;
}

int main() {
    ll N, M, V, P;
    cin >> N >> M >> V >> P;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());

    int low = 0, high = N;
    while (high - low > 1) {
        int mid = (high + low) / 2;
        if (isOk(N, M, V, P, A, mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }
    cout << low + 1 << endl;
}
