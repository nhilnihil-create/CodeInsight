#include <bits/stdc++.h>
using namespace std;

bool is_square(int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (i * i == n)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n, d;
    cin >> n >> d;
    int ans = 0;
    vector<vector<int>> vp(n, vector<int>(d, 0));
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < d; j++)
        {
            cin >> vp[i][j];
            /* code */
        }
    }
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            int sum = 0;
            for (size_t k = 0; k < d; k++)
            {
                sum += (vp[i][k] - vp[j][k]) * (vp[i][k] - vp[j][k]);
                /* code */
            }
            if (is_square(sum))
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}