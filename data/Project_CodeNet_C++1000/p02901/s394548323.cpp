#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;

int main() {
    int n, m;
    cin >> n >> m;
    int N = 1 << n;
    vector<int> dp(N, INF), A(m), B(m, 0);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        A[i] = a;
        rep(j, b) {
            int c;
            cin >> c;
            c--;
            int d = 1 << c;
            B[i] |= d;
        }
    }
    dp[0] = 0;
    rep(i, N) {
        rep(j, m) {
            int ni = i | B[j];
            dp[ni] = min(dp[ni], dp[i]+A[j]);
        }
    }
    if (dp[N-1]==INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << dp[N-1] << endl;
    return 0;
}