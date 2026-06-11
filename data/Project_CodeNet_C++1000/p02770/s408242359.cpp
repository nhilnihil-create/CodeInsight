#include <bits/stdc++.h>
using namespace std;

long long ceil_div(long long a, long long b)
{
    return (a + b - 1) / b;
}

int main()
{
    int k, q;
    cin >> k >> q;

    vector<long long> d(k);
    for (long long &dd : d)
    {
        cin >> dd;
    }

    long long n, x, m;
    for (int i = 0; i < q; i++)
    {
        cin >> n >> x >> m;
        long long ans = n - 1;
        long long sum = x;
        for (int i = 0; i < k; i++)
        {
            long long diff = d[i] % m;
            if (diff == 0)
            {
                ans -= ceil_div(n - i - 1, k);
            }
            sum += ceil_div(n - i - 1, k) * diff;
        }
        cout << ans - (sum / m - x / m) << endl;
    }
}
