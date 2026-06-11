#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int n, m, x; cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int perms = 1 << n;;
    int ans = 12345678;
    bool flag = true;
    for (int p = 0; p < perms; p++)
    {
        vector<int> level(m, 0);
        int cost = 0; flag = true;
        for (int i = 0; i < n; i++)
        {
            if ((p >> i) & 1)
            {
                cost += c[i];
                for (int j = 0; j < m; j++)
                {
                    level[j] += a[i][j];
                }
            }
        }
        for (int j = 0; j < m; j++)
        {
            if (level[j] < x) flag = false;
        }
        if (flag) ans = min(ans, cost);
    }
    if (ans == 12345678) cout << -1 << endl;
    else cout << ans << endl;
}
