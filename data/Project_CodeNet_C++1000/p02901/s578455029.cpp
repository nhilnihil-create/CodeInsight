#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

ll dp[1<<13]; // 状態sに到達する最小のコスト
int a[1010], b[1010];
int c[1010][15];

int main(){
    int n, m;
    cin >> n >> m;
    rep(i, m){
        cin >> a[i] >> b[i];
        rep(j, b[i]) cin >> c[i][j];
    }

    rep(i, 1<<13) dp[i] = LINF;
    dp[0] = 0;

    rep(i, m){
        int now = 0;
        rep(j, b[i]) now |= (1<<(c[i][j]-1)); 
        rep(bits, 1<<n){
            dp[bits|now] = min(dp[bits|now], dp[bits] + a[i]);
        }
    }

    if (dp[(1<<n)-1] == LINF) cout << -1 << endl;
    else cout << dp[(1<<n)-1] << endl;

    return 0;
}
