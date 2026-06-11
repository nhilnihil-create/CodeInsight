#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;
using Graph = vector<vector<ll>>;

int main()
{
    ll l, r;
    cin >> l >> r;

    if (r - l + 1 >= 2019)
    {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 2020;
    for (int i = l; i < r; i++)
    {
        for (int j = i + 1; j <= r; j++)
        {
            ll t1 = i % 2019;
            ll t2 = j % 2019;
            ans = min((t1 * t2) % 2019, ans);
        }
    }
    cout << ans << endl;
}