#include <bits/stdc++.h>

#define REP(i,n) for (int i=0;i<(n);++i)
#define rall(a) (a).rbegin(),(a).rend()

using namespace std;

using ll = long long;
using pii = pair<int, int>;

template <class T, class U> void amax(T& x, U y) {if (x < y) x = y;}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N);
    REP(i, N) cin >> A[i];

    vector<pii> Ai(N);
    REP(i, N) Ai[i] = pii(A[i], i);
    sort(rall(Ai));

    vector<vector<ll>> dp(N + 1, vector<ll>(N + 1));
    REP(k, N) {
        int Ap, p;
        tie(Ap, p) = Ai[k];
        REP(i, k + 1) {
            int j = k - i;
            amax(dp[i + 1][j], dp[i][j] + (ll)Ap * (p - i));
            amax(dp[i][j + 1], dp[i][j] + (ll)Ap * (N - 1 - j - p));
        }
    }

    ll result = 0;
    REP(i, N + 1) {
        int j = N - i;
        amax(result, dp[i][j]);
    }

    cout << result << endl;

    return 0;
}
