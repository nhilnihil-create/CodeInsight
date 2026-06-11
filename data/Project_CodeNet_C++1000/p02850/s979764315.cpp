#include <bits/stdc++.h>
using namespace std;

void solve(int N, vector<int> a, vector<int> b)
{
    vector<vector<int>> tree(N);
    for (int i = 0; i < N - 1; i++)
    {
        tree.at(a.at(i) - 1).push_back(b.at(i) - 1);
        tree.at(b.at(i) - 1).push_back(a.at(i) - 1);
    }

    int k = 0;
    map<pair<int, int>, int> color;

    vector<bool> visited(N);
    visited.at(0) = true;
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    while (!q.empty())
    {
        int u = q.front().first, c_u = q.front().second;
        q.pop();
        int c_v = 1;
        for (auto v : tree.at(u))
        {
            if (visited.at(v))
                continue;
            visited.at(v) = true;
            if (c_u == c_v)
                c_v++;
            color[make_pair(min(u, v), max(u, v))] = c_v;
            q.push(make_pair(v, c_v));
            k = max(k, c_v);
            c_v++;
        }
    }

    cout << k << endl;
    for (int i = 0; i < N - 1; i++)
    {
        cout << color.at(make_pair(a.at(i) - 1, b.at(i) - 1)) << endl;
    }
}

int main()
{
    int N;
    cin >> N;
    vector<int> a(N - 1);
    vector<int> b(N - 1);
    for (int i = 0; i < N - 1; i++)
    {
        cin >> a.at(i);
        cin >> b.at(i);
    }
    solve(N, move(a), move(b));
    return 0;
}
