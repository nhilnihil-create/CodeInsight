#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> c(n);
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        for (int j = 0; j < m; j++)
            cin >> v[i][j];
    }
    int all = 1 << n, mn = INT_MAX;
    for (int mask = 0; mask < all; mask++)
    {
        vector<int> nw(m);
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if ((mask >> i) & 1)
            {
                sum += c[i];
                for (int j = 0; j < m; j++)
                {
                    nw[j] += v[i][j];
                }
            }
        }
        bool ans = true;
        for (int i = 0; i < m; i++)
        {
            if (nw[i] < k)
            {
                ans = false;
                break;
            }
        }
        if (ans)
        {
            mn = min(mn, sum);
        }
    }
    if (mn == INT_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << mn << endl;
    }
}