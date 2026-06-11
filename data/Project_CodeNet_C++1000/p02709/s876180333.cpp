//#pragma GCC optimization ("O3")
//#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define ok puts("ok")
#define ll long long
#define pb push_back
#define mk make_pair
#define fr first
#define sc second
#define vi vector < int >
#define pl pair < ll, ll >
#define pi pair < int, int >
#define pii pair < int, pi >
#define next next123
#define left left123

const int N = 2007;
const ll INF = 1e18 + 7;

ll dp[N][N], ans;
pair < ll, int > a[N];
int n;

main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        scanf("%lld", &a[i].fr);
        a[i].sc = i;
    }
    sort(a + 1, a + n + 1, greater<pi>());
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= i; j++){
            if (j != i)
                dp[i][j] = dp[i - 1][j] + a[i].fr * abs(a[i].sc - (n - i + j + 1));
            if (j != 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + a[i].fr * abs(a[i].sc - j));
        }
    }
    for (int j = 0; j <= n; j++)
        ans = max(ans, dp[n][j]);
    cout << ans;
}
