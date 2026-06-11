#include <iostream>
#include <queue>
#include <utility>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, m, s, t, a, b, v[100005][3];
vector<int> g[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        cin >> a >> b, g[a].push_back(b);
    cin >> s >> t;
    queue<pair<int, int>> q;
    q.push({s, 0});
    v[s][0] = 1;

    while (!q.empty())
    {
        auto tr = q.front();
        q.pop();
        if (tr.first == t && tr.second % 3 == 0)
            return cout << tr.second / 3 << endl, 0;
        for (int i : g[tr.first])
            if (!v[i][(tr.second + 1) % 3])
                q.push({i, tr.second + 1}), v[i][(tr.second + 1) % 3] = 1;
    }
    cout << -1 << endl;
}