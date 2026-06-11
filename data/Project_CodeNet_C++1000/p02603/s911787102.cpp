#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    ll ans = 1000;
    vector<ll> A(N);
    rep(i, N) { cin >> A[i]; }
    for (int i = 0; i < N - 1; i++) {
        if (A[i + 1] > A[i])
            ans = (ans / A[i]) * A[i + 1] + (ans % A[i]);
    }

    cout << ans << endl;
}