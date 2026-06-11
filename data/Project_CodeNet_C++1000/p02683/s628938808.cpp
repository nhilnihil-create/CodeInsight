#include "bits/stdc++.h"
#pragma GCC optimize "03"
using namespace std;

#define int long long int
#define double long double
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define rep(i,a,b) for (int i = a; i < b; ++i)
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef LOCAL
#define dbg(...) ;
#define endl '\n'
#endif

const int inf = 1e15;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;



signed main(){
    IOS;
    int n, m, x;
    cin >> n >> m >> x;
    int a[n][m];
    int c[n];
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = inf;
    for (int i = 0; i < (1 << n); i++) {
        int s[m] = {0};
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sum += c[j];
                for (int k = 0; k < m; k++)
                    s[k] += a[j][k];
            }
        }
        for (int j = 0; j < n; j++) {
            int flag = 1;
            for (int k = 0; k < m; k++) {
                if (s[k] < x) flag = 0;
            }
            if (flag) ans = min(ans, sum);
        }
    }
    if (ans == inf) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}