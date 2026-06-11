#include <iostream>
#include <vector>

#define int long long int

using namespace std;

const int mod = 998244353;

int pow_mod(int a, int p)
{
    int cur = a, ans = 1;

    while (p > 0)
    {
        if (p & 1)
            ans = (ans * cur) % mod;
        p /= 2;
        cur = (cur * cur) % mod;
    }

    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> d(n);
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
        cnt[d[i]]++;
    }

    if (d[0] != 0 || cnt[0] != 1)
    {
        cout << "0\n";
        return 0;
    }

    int res = 1;
    for (int i = 1; i < n; i++)
        res = (res * pow_mod(cnt[i - 1], cnt[i])) % mod;

    cout << res << "\n";

    return 0;
}
