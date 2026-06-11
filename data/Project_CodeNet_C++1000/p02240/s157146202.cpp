#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, start, n) for (int i = (int)(start); i < (int)(n); ++i)
void search(vector<vector<int> > &G, int *color, int s, int id)
{
    color[s] = id; //sは訪問済み
    stack<int> q;
    q.push(s);
    while (q.empty() == false)
    {
        int p = q.top();
        q.pop();
        rep(i, 0, G[p].size())
        {
            int new_p = G[p][i];
            if (color[new_p] == 0)
            {
                color[new_p] = id;
                q.push(new_p);
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > G(n, vector<int>(0));
    int color[n] = {};
    int s, t;
    rep(i, 0, m)
    {
        scanf("%d %d", &s, &t);
        G[s].push_back(t);
        G[t].push_back(s);
    }
    int id(0);
    rep(i, 0, n)
    {
        if (color[i] == 0)
        {
            search(G, color, i, ++id);
        }
    }
    int q;
    cin >> q;
    rep(i, 0, q)
    {
        scanf("%d %d", &s, &t);
        if (color[s] == color[t])
            printf("yes\n");
        else
            printf("no\n");
    }
}
