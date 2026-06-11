#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void search(const vector<vector<int>> &g, queue<int> &q, vector<bool> &tr, vector<int> &cnt, int k, int i)
{
    int l = q.size();
    for (int j = 0; j < l; j++)
    {
        int s = q.front(); q.pop();
        for (int t:g[s])
        {
            if (tr[t]) 
            {
                q.push(t);
                if (t > i) cnt[k]++;
                tr[t] = false;
            }
        }
    }
    if (q.size() < 1) return;
    else search(g, q, tr, cnt, k+1, i);
}

int main(void)
{
    int n, x, y; cin >> n >> x >> y;
    vector<vector<int>> g(n, vector<int>(0));
    for (int i = 0; i < n - 1; i++)
    {
        g[i].push_back(i + 1);
        g[i + 1].push_back(i);
    }
    g[x - 1].push_back(y - 1);
    g[y - 1].push_back(x - 1);

    vector<int> cnt(n, 0);
    for (int i = 0; i < n; i++)
    {
        queue<int> q; q.push(i);
        vector<bool> tr(n, true); tr[i] = false;
        search(g, q, tr, cnt, 0, i);
    }
    for (int k = 0; k < n - 1; k++)
    {
        cout << cnt[k] << endl;
    }
}