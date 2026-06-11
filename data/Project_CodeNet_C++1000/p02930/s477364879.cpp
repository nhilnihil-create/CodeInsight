#include "bits/stdc++.h"

using namespace std;

int n;
int ans[512][512];

void f(int l = 0, int r = n, int dep = 1)
{
    if (l + 1 == r)
        return;
    int m = (l + r) / 2;
    for (int i = l; i < m; i++)
    {
        for (int j = m; j < r; j++)
        {
            ans[i][j] = dep;
        }
    }
    f(l, m, dep + 1);
    f(m, r, dep + 1);
}

void solve()
{
    cin >> n;
    f();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            cout << ans[i][j] << ' ';
        }
        cout << "\n";
    }
}

int main()
{
    solve();
    cerr << "\"努力不足ですね！\"" << endl;
    return 0;
}