#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int mod = 1000000007;
int binpow(int a, int b, int mod)
{
    int ans = 1;
    a = a % mod;
    b = b % mod;
    if (b == 0)
        return 1;
    while (b)
    {
        if (b & 1)
            ans = ((ans % mod) * (a % mod)) % mod;
        a = ((a % mod) * (a % mod)) % mod;
        b >>= 1;
    }
    return ans % mod;
}

//read question carefully!

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << 0 << "\n";
            return 0;
        }
        int ans = binpow(10, n, mod) - (2 * (binpow(9, n, mod)) % mod) + binpow(8, n, mod) + mod;
        cout << ans % mod << "\n";
    }
}
