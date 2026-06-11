#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <iomanip>
#include <math.h>
#include <fstream>

using namespace std;

long long mod = 1000000007;

void dfs(int p, int prev, vector<int> &a, vector<int> &dp, int dpl, vector<vector<int>> &v, vector<int> &res)
{
    int l = -1, r = dpl, mid;
    while (r - l > 1)
    {
        mid = (l + r) / 2;
        if (dp[mid] >= a[p])
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    int temp = dp[r];
    dp[r] = a[p];
    if (temp == -1)
    {
        dpl++;
    }
    res[p] = dpl;
    for (int i = 0; i < v[p].size(); i++)
    {
        if (v[p][i] == prev)
        {
            continue;
        }
        dfs(v[p][i], p, a, dp, dpl, v, res);
    }
    dp[r] = temp;
}

int main()
{
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    // ifstream cin("in.txt");
    // ofstream cout("out.txt");
    
    
    // int t;
    // cin >> t;
    // for (int qwe = 0; qwe < t; qwe++)
    // {
    //     cout << "Case #" << qwe + 1 << ": ";
    // }


    int n, m, x;
    cin >> n >> m >> x;
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
    int rez = 999999999;
    for (int i = 0; i < (1 << n); i++)
    {
        vector<int> v(m, 0);
        int cost = 0;
        for (int j = 0; j < n; j++)
        {
            if ((i & (1 << j)) == 0)
            {
                continue;
            }
            cost += c[j];
            for (int k = 0; k < m; k++)
            {
                v[k] += a[j][k];
            }
        }
        bool good = true;
        for (int j = 0; j < m; j++)
        {
            if (v[j] < x)
            {
                good = false;
                break;
            }
        }
        if (good)
        {
            rez = min(rez, cost);
        }
    }
    if (rez == 999999999)
    {
        rez = -1;
    }
    cout << rez << '\n';


    return 0;
}
