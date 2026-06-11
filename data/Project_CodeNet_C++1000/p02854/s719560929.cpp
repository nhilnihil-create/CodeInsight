#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define int long long

signed main()
{
    int n;
    vector<int> a;
    vector<int> sum;

    cin >> n;

    a.resize(n);
    sum.resize(n + 1, 0);

    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    for(int i = 1; i <= n; ++i)
    {
        sum[i] = sum[i - 1] + a[i - 1];
    }

    int ans = 200000LL * 2020202020LL; 

    for(int i = 1; i <= n; ++i)
    {
        int l = sum[i];
        int r = sum[n] - sum[i];

        ans = min(ans, abs(l - r));
    }

    cout << ans << endl;
}