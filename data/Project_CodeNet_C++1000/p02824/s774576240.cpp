#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;

ll N, M, V, P;

bool isOK(vector<ll> A, ll key) {
    if (key < P)
        return true;
    A[key] += M;
    ll tmp = A[key];
    if (A[P - 1] > tmp)
        return false;
    ll score = 0;
    score += (P - 1) * M;  // p-1まで
    score += (N - key) * M; // keyより下
    for (int i = P - 1; i < key; i++) {
        score += min(M, max(0LL, tmp - A[i])); // p-1からkeyまで
    }

    return score >= M * V;
}

int main() {
    cin >> N >> M >> V >> P;
    vector<ll> A(N);
    rep(i, N) { cin >> A[i]; }

    sort(all(A), greater<ll>());
    ll ok = -1, ng = N;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (isOK(A, mid))
            ok = mid;
        else
            ng = mid;
    }

    cout << ok + 1 << endl;
    return 0;
}