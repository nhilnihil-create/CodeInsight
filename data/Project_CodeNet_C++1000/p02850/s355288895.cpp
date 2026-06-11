#include "bits/stdc++.h"

using namespace std;
using ll = long long int;

constexpr int MaxN = 100000 + 10;
vector<int> G[MaxN];
vector<pair<int, int>> E;
map<pair<int, int>, int> C;
int maxCount;

void Paint(int from, int color)
{
    for (auto to : G[from])
    {
        if (C.find(make_pair(from, to)) == C.end())
        {
            C[make_pair(from, to)] = C[make_pair(to, from)] = color;
            color = (color + 1) % maxCount;
            Paint(to, color);
        }
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
        E.emplace_back(a, b);
    }

    maxCount = 0;
    for (int i = 0; i < n; i++)
    {
        maxCount = max(maxCount, (int) G[i].size());
    }

    Paint(0, 0);

    cout << maxCount << endl;
    for (auto &pair : E)
    {
        cout << C[pair] + 1 << endl;
    }
}