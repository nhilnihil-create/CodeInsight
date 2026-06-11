#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    ll k;
    cin >> n >> k;

    vector<vector<int>> next(60, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        cin >> next[0][i];
        next[0][i]--;
    }
    for (int d = 0; d + 1 < 60; d++)
    {
        for (int v = 0; v < n; v++)
        {
            next[d + 1][v] = next[d][next[d][v]];
        }
    }
    int v = 0;
    for (int d = 0; d < 60; d++)
    {
        if (k & (1LL << d)) v = next[d][v];
    }

    cout << v + 1 << endl;

    return 0;
}