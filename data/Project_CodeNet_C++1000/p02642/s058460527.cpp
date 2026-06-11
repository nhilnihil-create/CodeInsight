#include <bits/stdc++.h>
// #include <atcoder/all> // NOTE: AtCoderライブラリ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
// using namespace atcoder; // NOTE: AtCoderライブラリ
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef pair<int, int> pii;
// #define INF __INT32_MAX__
#define INF 1e9
#define LINF __LONG_LONG_MAX__

int main() {
    int N; cin >> N;
    vi A(N); rep(i, N) cin >> A[i];
    
    sort(A.begin(), A.end());

    const int AMAX = 1e6;
    vector<bool> dp(AMAX + 1, false);
    vector<bool> used(AMAX + 1, false);
    
    rep(i, N) {
        int a = A[i];
        if (used[a]) {
            dp[a] = true;
            continue;
        }
        used[a] = true;

        for (int j = 2 * a; j <= AMAX; j += a) {
            dp[j] = true;
        }
    }

    int cnt = 0;
    rep(i, N) {
        if (!dp[A[i]]) cnt++;
    }

    cout << cnt << endl;
}
