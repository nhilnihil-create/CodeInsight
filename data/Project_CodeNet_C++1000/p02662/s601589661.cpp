//In The Name of Allah
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 3010;
const ll mod = 998244353;

ll a[N], dp[N][N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, s;
    cin >> n >> s;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    dp[0][0] = 1;
    for (int i = 1; i <= n; i ++)
        for (int j = 0; j < N; j ++)
            dp[i][j] = (2 * dp[i - 1][j] + (a[i] <= j ? dp[i - 1][j - a[i]] : 0)) % mod;
    cout << dp[n][s];
    return 0;
}
