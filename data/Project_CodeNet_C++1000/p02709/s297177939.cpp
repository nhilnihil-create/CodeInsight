#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
#define MOD 1000000007LL
#define N 2123

using namespace std;

int n;

ll dp[N][N], ans;

struct child {
    ll value;
    int idx;
} children[N];

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;

    for(int i=1; i <= n; ++i) {
        cin >> children[i].value;
        children[i].idx = i;
    }

    sort(children + 1, children + 1 + n, [](child a, child b){ return a.value > b.value;});

    for(int i=1; i <= n; ++i) {
        for(int j=1; j <= i; ++j) {
            dp[j][i - j] = max(dp[j][i - j], dp[j - 1][i - j] + ((abs(children[i].idx - j) * children[i].value)));
            dp[i - j][j] = max(dp[i - j][j], dp[i - j][j - 1] + ((abs(n - j + 1 - children[i].idx) * children[i].value)));
        }
    }

    for(int i=1; i <= n; ++i) {
        ans = max(ans,dp[i][n - i]);
    }
    cout << ans << endl;


    return 0;
}
