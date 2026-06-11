#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) Rep(i, 0, n)
#define all(a) (a).begin(), (a).end()
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;
//const int mod = 998244353;

int n;
int digit(int x)
{
    int res = 0;
    while (x > 0)
    {
        res++;
        x /= 10;
    }
    return res;
}
int calc(int x)
{
    while (x >= 10)
        x /= 10;
    return x;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    int cnt[10][10] = {};
    for (int i = 1; i <= n; i++)
    {
        int tail = i % 10;
        int head = calc(i);
        cnt[head][tail]++;
    }
    int ans = 0;
    rep(i, 10) rep(j, 10) ans += cnt[i][j] * cnt[j][i];
    cout << ans << endl;
}
