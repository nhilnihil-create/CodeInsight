#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int gcd(int m, int n)
{
    if (m < n)
    {
        int tmp = m;
        m = n;
        n = tmp;
    }

    while (1)
    {
        int mod = m % n;
        if (mod == 0)
            return n;
        m = n;
        n = mod;
    }
}

int main(void)
{
    int k, ans = 0;
    cin >> k;

    for (int i = 1; i <= k; i++)
        for (int j = 1; j <= k; j++)
            for (int l = 1; l <= k; l++)
                ans += gcd(gcd(i, j), l);

    cout << ans << endl;
    return 0;
}