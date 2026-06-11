#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

ll MOD = 998244353;
const int N = 3005, S = 3005;
ll expo[N], dp[S][N];
vector<int> a;
int n, s;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    a.assign(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    memset(expo, 0, N * sizeof(ll));
    memset(dp, 0, N * S * sizeof(ll));
    expo[0] = 1;
    for(int i = 1; i <= N; i++){
        expo[i] = expo[i-1] * i;
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int sum = 0; sum <= s; sum++){
            if(sum >= a[i])
                dp[i][sum] += dp[i-1][sum - a[i]];
            dp[i][sum] %= 998244353;
            dp[i][sum] += 2 * dp[i - 1][sum];
            dp[i][sum] %= 998244353;
        }
    }
    cout << dp[n][s];
}