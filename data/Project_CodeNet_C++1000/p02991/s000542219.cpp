#include <bits/stdc++.h>

#define MAX 100005

using namespace std;

int n, m, s, t;
vector<int> G[MAX];
int8_t mark[MAX];;

int bfs()
{
        queue<pair<int,int>> q;
        int ls = 0;
        int kkp = 0;
        q.emplace(s,0);

        while (!q.empty()) {
                auto curr = q.front();
                q.pop();
                if (curr.second != 3) {
                        kkp += (ls == 3);
                        ls = curr.second;

                        if ((mark[curr.first] & (1<<curr.second))) continue;
                        mark[curr.first] |= (1<<curr.second);
                        for (auto e : G[curr.first])
                                q.emplace(e, curr.second+1);
                } else {
                        if (curr.first == t) return kkp+1;
                        else if ((mark[curr.first] & (1<<curr.second))) continue;

                        mark[curr.first] |= (1<<curr.second);
                        ls = curr.second;
                        for (auto e : G[curr.first])
                                q.emplace(e, 1);
                }
        }
        return -1;
}

int main()
{
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
                int u, v;
                cin >> u >> v;
                G[u].push_back(v);
        }
        cin >> s >> t;
        cout << bfs() << endl;
        return 0;
}