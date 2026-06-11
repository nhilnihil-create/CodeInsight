#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define pb push_back
#define F first
#define S second
const int mod = 1e9 + 7, A = 1e5 + 5;
int n, k, cnt[A];
int mul(int x, int y) {return (1LL * x * y) % mod;}
int add(int x, int y) {return ((x + y) % mod + mod) % mod;}
int fp(int x, int y)
{
    if (!y) return 1;
    ll acc = fp(x, y / 2);
    acc = mul(acc, acc);
    if (y & 1)
        acc = mul(acc, x);
    return acc;
}
int solve(int x)
{
    int ret = fp(k / x, n);
    for (int i = 2 * x; i <= k; i += x)
        ret = add(ret, -cnt[i]);
    return cnt[x] = ret;
}
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> k;
    int ans = 0;
    for (int i = k; i > 0; i--)
        ans = add(ans, mul(i, solve(i)));
    cout << ans;
    return 0;
}