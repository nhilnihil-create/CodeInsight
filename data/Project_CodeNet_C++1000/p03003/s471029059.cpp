#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e3 + 10;
const int MOD = 1e9 + 7;
ll dp[N][N][2][2], A[N], B[N], prea[N], preb[N], pos[N];
void add(ll& x, ll y) {
    x += y;
    x %= MOD;
}
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for(int i = 1; i <= m; i++) {
        cin >> B[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int a = 0; a < 2; a++) {
                for(int b = 0; b < 2; b++) {
                    ll need = 0, need2 = 0;
                    if(A[i] == B[j]) {
                        need2 = dp[i-1][j-1][0][0] + 1;
                    }
                    if(a==0 && b==0) add(dp[i][j][a][b], dp[i][j-1][1][0]+dp[i-1][j][0][1]+dp[i-1][j-1][0][0]+need2);
                    if(a==1 && b==0) add(dp[i][j][a][b], dp[i][j-1][1][0]+need2);
                    if(a==0 && b==1) add(dp[i][j][a][b], dp[i-1][j][0][1]+need2);
                    if(a==1 && b==1) add(dp[i][j][a][b], need2);
                }
            }
        }
    }
    cout << (1+dp[n][m][0][0])%MOD << '\n';
    return 0;
}