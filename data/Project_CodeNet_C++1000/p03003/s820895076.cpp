#include "bits/stdc++.h"
using namespace std;

#define sz(x) (int)(x.size())
#define FOR(i,L,R) for(int i = L; i <= R; i++)
#define int long long

const int N = 2e5 + 2, inf = 1e18;

int n, m;
std::vector<int> A, B;
int dp[2002][2002];
const int mod = 1e9 + 7;

int go(int i, int j) {
    if (i == n || j == m)
        return 1;
    int &ret = dp[i][j];
    if (~ret)
        return ret;
    int ans = go(i + 1, j)%mod + go(i, j + 1)%mod - (A[i] != B[j] ? go(i + 1, j + 1)%mod : 0);
    while (ans < 0) ans += mod;
    ans %= mod;
    return ret = ans;
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    A.resize(n);
    B.resize(m);
    for(int &x : A) cin >> x;
    for(int &x : B) cin >> x;

    memset(dp, -1, sizeof(dp));
    int ans = go(0,0);
    cout << ans;
}
