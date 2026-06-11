#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> tree(n,vector<int>());
    vector<vector<int>> sideId(n,vector<int>());
    for(int i = 0; i < n-1; ++i)
    {
        int a,b;
        cin >> a >> b;
        --a;
        --b;
        tree[a].push_back(b);
        sideId[a].push_back(i);
        tree[b].push_back(a);
        sideId[b].push_back(i);
    }

    vector<int> colors(n-1);
    vector<bool> checker(n);
    queue<pair<int,int>> que;

    que.push(make_pair(0,-1));
    checker[0] = true;
    int variation = 0;
    while(!que.empty())
    {
        pair<int,int> p = que.front();
        int cur = p.first;
        que.pop();
        int tSize = (int)tree[cur].size();
        int color = 0;
        for(int i = 0; i < tSize; ++i)
        {
            int next = tree[cur][i];
            if(checker[next])
            {
                continue;
            }
            int sid = sideId[cur][i];
            int diff = 1;
            if(p.second >= 0)
            {
                diff = p.second == color+1 ? 2 : 1;
            }
            color += diff;
            colors[sid] = color;
            que.push(make_pair(next,color));
            checker[next] = true;
            variation = max(variation,color);
        }
    }
    cout << variation << endl;
    for(int i : colors)
    {
        cout << i << endl;
    }
}