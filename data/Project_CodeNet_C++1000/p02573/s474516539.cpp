#include<iostream>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;

typedef vector< set<int> > nodeList;

vector< vector<int> > bfs(nodeList& nodes)
{
    vector< vector<int> > group;
    int groupNum = -1;
    vector<int> color(nodes.size(), WHITE);
    color[0] = -1;

    //i=1~nまで繰り返す
      //iをしてんとしてbfsで探索
    for (int i = 1; i < nodes.size(); i++)
    {
        queue<int> q;
        if (color[i] == BLACK)continue;
        group.emplace_back();
        groupNum++;

        q.push(i);
        while (!q.empty())
        {
            int u = q.front(); q.pop();
            for (auto v : nodes[u])
            {
                if (color[v] == BLACK)continue;
                q.push(v);
                group[groupNum].emplace_back(v);
                color[v] = BLACK;
            }
        }
    }
    return group;
}

int main()
{
    int n, m;
    cin >> n >> m;

    if (m == 0)
    {
        cout << 1 << endl;
        return 0;
    }

    nodeList nodes(n + 1);
    rep(i, m)
    {
        int a, b;
        cin >> a >> b;
        set<int>::iterator itr1 = nodes[a].find(b);
        if (itr1 == nodes[a].end())
        {
            nodes[a].insert(b);
        }

        set<int>::iterator itr2 = nodes[b].find(a);
        if (itr2 == nodes[b].end())
        {
            nodes[b].insert(a);
        }
    }

    //グループ分け
    vector< vector<int> > group = bfs(nodes);

    //グループで最も人数が多いのを出力
    int ans = 0;
    rep(i, group.size())
    {
        ans = max(int(group[i].size()), ans);
    }
    cout << ans << endl;

    return 0;
}