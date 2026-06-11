
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 998244353;
const int N = 3005;
int n, s;
int A[N];
int dp[N][N];

ll f(int i, int sum) {
    if (i == n) {
        if (sum == 0)
            return 1;
        return 0;
    }
    if (dp[i][sum] != -1) return dp[i][sum];
    int v = A[i];
    ll res = 0;
    if (sum >= v)
        res = (res + f(i + 1, sum - v)) % MOD;
    res = (res + f(i + 1, sum) * 2 % MOD) % MOD;
    return dp[i][sum] = res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    memset(dp, 255, sizeof dp);
    ll res = f(0, s);
    cout << res << endl;


    return 0;
}

