#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;

vector<int> v[N];
int cost[N][3];

int main()
{
    //ios::sync_with_stdio(false);cin.tie(nullptr);ios_base::sync_with_stdio(false);
    int n, m, s, t, x, y;
    memset(cost, -1, sizeof cost);
    cin >> n >> m;
    while (m--)
    {
        cin >> x >> y;
        v[x].push_back(y);
    }
    cin >> s >> t;
    cost[s][0] = 0;
    queue<pair<int, int>> q;
    q.push({s, 0});
    while (!q.empty())
    {
        x = q.front().first, y = q.front().second;
        q.pop();
        for (auto it: v[x])
        {
            int newCost = (y + 1) % 3;
            if (cost[it][newCost] == -1)
            {
                cost[it][newCost] = cost[x][y] + 1;
                q.push({it, newCost});
            }
        }
    }
    cout << (cost[t][0] == -1? -1: cost[t][0] / 3);
    return 0;
}