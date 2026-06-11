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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M, K;
    cin >> N >> M >> K;
    vector<ll> A(N + 1, 0), B(M + 1, 0);
    rep(i, N) { cin >> A[i + 1]; }
    rep(i, M) { cin >> B[i + 1]; }

    rep(i, N) { A[i + 1] += A[i]; }

    rep(i, M) { B[i + 1] += B[i]; }

    ll ans = 0;
    rep(i, N + 1) {
        ll tmp = i;
        if (A[i] > K)
            break;
        else {
            ll nokori = K - A[i];
            tmp += upper_bound(all(B), nokori) - B.begin() - 1;
        }

        ans = max(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}