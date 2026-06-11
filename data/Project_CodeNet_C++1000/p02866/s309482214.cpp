#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

long long quick_powll(long long x, long long n){
    if(n == 0)
    return 1;
    if(n % 2 == 0)
    return quick_powll(x * x % MOD, n / 2);
    else
    return x * quick_powll(x, n - 1) % MOD;
}

int main()
{
    int n;
    cin >> n;
    vector<int> d(n, 0);
    vector<int> dd(n);
    int maxd = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> dd[i];
        d[dd[i]]++;
        maxd = max(maxd, dd[i]);
    }

    long long ans = 0;
    if(d[0] == 1 && dd[0] == 0)
    {
        int i = 0;
        for (i = maxd; i >= 0; i--)
        {
            if(d[i] == 0)break;
        }
        if(i == -1)
        {
            ans = 1;
            for (int i = 1; i <= maxd; i++)
            {
                ans *= quick_powll(d[i - 1], d[i]);
                ans %= MOD;
            }
        }
    }

    cout << ans << endl;
}