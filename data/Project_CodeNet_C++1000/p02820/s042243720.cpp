#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, k;
    cin >> n >> k;
    int r, s, p;
    cin >> r >> s >> p;
    string t;
    cin >> t;

    bool a[200010];

    ll ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (t[i] == t[i + k])
        {
            a[i + k] = !a[i];
        }

        if (!a[i])
        {
            if (t[i] == 'r')
            {
                ans += p;
            }
            else if (t[i] == 's')
            {
                ans += r;
            }
            else
            {
                ans += s;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
