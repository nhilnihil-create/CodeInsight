#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;

int n, m, q;
vector<vi> ip;
deque<int> v;
int ans;

void dfs(int cnt, int last)
{
    if (cnt == n)
    {
        int curr = 0;
        for (auto a : ip)
        {
            if (v[a[1]] - v[a[0]] == a[2])
                curr += a[3];
        }
        ans = max(ans, curr);
        return;
    }
    for (int i = last; i <= m; i++)
    {
        v.push_back(i);
        dfs(cnt + 1, i);
        v.pop_back();
    }
}

signed main()
{
    cin >> n >> m >> q;
    for (int i = 0; i < q; i++)
    {
        vi x(4);
        for (int i = 0; i < 4; i++)
            cin >> x[i];
        x[0]--;
        x[1]--;
        ip.push_back(x);
    }
    dfs(0, 1);
    cout << ans;
}