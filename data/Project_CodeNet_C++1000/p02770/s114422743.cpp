#include <iostream>
#include <vector>

using namespace std;

typedef long long llong;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    llong k, q;
    cin >> k >> q;

    vector<llong> d(k);
    for (llong i = 0; i < k; i++)
        cin >> d[i];

    while (q--)
    {
        llong n, x, m;
        cin >> n >> x >> m;
        x %= m;

        llong result = n - 1;
        llong total_sum = 0;

        for (llong i = 0; i < k; i++)
        {
            llong total_times = (n - 2 - i + k) / k;

            llong d_mod = d[i] % m;
            total_sum += total_times * d_mod;

            if (d[i] % m == 0)
                result -= total_times;
        }

        result -= (x + total_sum) / m;
        cout << result << "\n";
    }

    return 0;
}
