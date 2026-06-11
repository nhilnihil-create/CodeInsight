#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void)
{
    int n, m; cin >> n >> m;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    vector<vector<int>> g(n, vector<int>(0));
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        g[a-1].push_back(b-1);
        g[b-1].push_back(a-1);
    }
    vector<bool> tr(n, true);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (tr[i])
        {
            bool flag = true;
            tr[i] = false;
            for (int t:g[i])
            {
                if (h[i] > h[t]) tr[t] = false;
                else
                {
                    flag = false; break;
                }
            }
            if (flag) ans++;
        }
    }
    cout << ans << endl;
}