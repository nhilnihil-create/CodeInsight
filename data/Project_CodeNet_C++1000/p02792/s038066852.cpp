#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ll long long
#define P pair<int,int>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MOD = 1000000007;
const int INF = 2002002002;
const ll LLINF = 9009009009009009009;
using namespace std;

int main() {
    fast_io
    int n;
    cin >> n;
    // [先頭の桁][末尾のけた]
    int c[9][9];
    rep(i,9)rep(j,9) c[i][j] = 0;
    ll first, last, num;
    rep(i,n) {
        // 数字
        num = i + 1;
        // 末尾の桁
        last = num % 10;
        // 末尾の桁が0なら飛ばす
        if (!last) continue;
        // 先頭の桁
        while (num >= 10) num /= 10;
        first = num;
        c[first-1][last-1]++;
    }
    ll ans = 0;
    rep(i,9)rep(j,9) ans += c[i][j] * c[j][i];
    cout << ans << endl;
    return 0;
}