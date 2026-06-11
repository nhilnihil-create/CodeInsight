#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N);
    for (int i = 0; i < M; i++)
    {
        int ui, vi;
        cin >> ui >> vi;
        ui--;
        vi--;
        graph.at(ui).push_back(vi);
    }
    int S, T;
    cin >> S >> T;
    S--;
    T--;

    vector<vector<bool>> reachable(N, vector<bool>(3, false));
    reachable.at(S).at(0) = true;
    queue<tuple<int, int, int>> q;
    q.push(make_tuple(S, 0, 0));
    while (!q.empty())
    {
        int u = get<0>(q.front()), h = get<1>(q.front()), d = get<2>(q.front());
        q.pop();

        if (u == T && h == 0)
        {
            cout << d << endl;
            return 0;
        }

        h++;
        if (h == 3)
        {
            h = 0;
            d++;
        }
        for (auto v : graph.at(u))
        {
            if (reachable.at(v).at(h))
                continue;
            reachable.at(v).at(h) = true;
            q.push(make_tuple(v, h, d));
        }
    }
    cout << -1 << endl;
}