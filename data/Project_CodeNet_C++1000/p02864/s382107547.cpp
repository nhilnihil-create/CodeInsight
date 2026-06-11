#include <bits/stdc++.h>

using namespace std;

long long D[302][301], H[302];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> H[i];
    }
    H[n+1] = 0;
    for (int i = 0; i <= k; i++)
    {
        D[0][i] = 0;
    }
    for (int i = 1; i <= n+1; i++)
    {
        D[i][0] = D[i-1][0] + max(0ll, H[i]-H[i-1]);
        for (int y = 1; y <= k; y++)
        {
            D[i][y] = D[i-1][y] + max(0ll, H[i]-H[i-1]);
            for (int u = 1; u <= y; u++)
            {
                if (i-u >= 0)
                {
                    D[i][y] = min(D[i][y], D[i-u-1][y-u] + max(0ll, H[i]-H[i-u-1]));
                }
            }
        }
    }
    cout << D[n+1][k];
    return 0;
}
