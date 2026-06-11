#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int v[n];
    vector<int> a[n];
    for (int i = 0; i < n; i++)
        cin >> v[i];
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        a[u - 1].push_back(v - 1);
        a[v - 1].push_back(u - 1);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < a[i].size(); j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    // }
    // cout << endl;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int s = a[i].size();
        if (s == 0)
        {
            cnt++;
            continue;
        }

        int t = true;
        for (int j = 0; j < s; j++)
        {
            if (v[i] <= v[a[i][j]])
            {
                t = false;
                break;
            }
        }
        if (t)
        {

            cnt++;
        }
    }
    cout << cnt;
}