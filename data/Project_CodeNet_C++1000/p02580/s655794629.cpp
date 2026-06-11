#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
 
int main()
{
#ifdef WIN32
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int h, w, m;
    cin >> h >> w >> m;
    int x, y;
    int row[h + 1], col[w + 1];
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    set<pair<int, int>> s;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        s.insert({x, y});
        row[x]++;
        col[y]++;
    }
    x = 1;
    y = 1;
    for (int i = 1; i <= h; i++)
    {
        if (row[i] > row[x])
            x = i;
    }
    for (int i = 1; i <= w; i++)
    {
        if (col[i] > col[y])
            y = i;
    }
    int ans = 0;
    for (int i = 1; i <= w; i++)
    {
        if (s.find({x, i}) != s.end())
        {
            ans = max(ans, row[x] + col[i] - 1);
        }
        else
        {
            ans = max(ans, row[x] + col[i]);
        }
    }
    for (int i = 1; i <= h; i++)
    {
        if (s.find({i, y}) != s.end())
        {
            ans = max(ans, row[i] + col[y] - 1);
        }
        else
        {
            ans = max(ans, row[i] + col[y]);
        }
    }
    cout << ans << "\n";
    return 0;
}