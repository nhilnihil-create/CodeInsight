#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[--x]++;
    }
    sort(a.begin(), a.end());

    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i];

    int x = n;
    for (int k = 1; k <= n; k++)
    {
        while (true)
        {
            int l = -1;
            int r = n;
            while (r - l > 1)
            {
                int m = (l + r) / 2;
                if (a[m] < x) l = m;
                else r = m;
            }
            int s = pref[r] + (n - r) * x;
            if (s < k * x) x--;
            else break;
        }
        cout << x << "\n";
    }

    return 0;
}
