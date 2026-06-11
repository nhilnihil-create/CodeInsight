#include <bits/stdc++.h>
using namespace std;

pair<int, int> get_match(int x, int y)
{
    if (x < y)
        return make_pair(x, y);
    else
        return make_pair(y, x);
}

vector<vector<int>> graph;
vector<int> depth;
vector<bool> visited;

int dfs(int v)
{
    if (visited.at(v))
    {
        if (depth.at(v) == 0)
        {
            return -1;
        }
        return depth.at(v);
    }

    visited.at(v) = true;
    int res = 1;
    for (auto u : graph.at(v))
    {
        int res_u = dfs(u);
        if (res_u < 0)
        {
            return -1;
        }
        res = max(res, res_u + 1);
    }
    depth.at(v) = res;
    return res;
}

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> A(N, vector<int>(N - 1));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            cin >> A.at(i).at(j);
            A.at(i).at(j)--;
        }
    }

    map<pair<int, int>, int> m_to_v;
    vector<pair<int, int>> v_to_m;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 1; j++)
        {
            pair<int, int> m = get_match(i, A.at(i).at(j));
            if (m_to_v.count(m) == 0)
            {
                int v = m_to_v.size();
                m_to_v[m] = v;
                v_to_m.push_back(m);
            }
        }
    }

    graph = vector<vector<int>>(m_to_v.size());
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N - 2; j++)
        {
            pair<int, int> m0 = get_match(i, A.at(i).at(j)), m1 = get_match(i, A.at(i).at(j + 1));
            int v0 = m_to_v.at(m0), v1 = m_to_v.at(m1);
            graph.at(v0).push_back(v1);
        }
    }

    depth = vector<int>(m_to_v.size(), 0);
    visited = vector<bool>(m_to_v.size(), false);
    int res = 0;
    for (unsigned int v = 0; v < m_to_v.size(); v++)
    {
        int d = dfs(v);
        if (d < 0)
        {
            cout << -1 << endl;
            return 0;
        }
        res = max(res, d);
    }
    cout << res << endl;
}