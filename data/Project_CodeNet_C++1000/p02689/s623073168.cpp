#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n, m, from, to, res = 0;
    cin >> n >> m;

    vector<ll> h(n + 1);
    vector<set<int>> edges(n + 1, set<int>());

    for(int i = 1; i <= n; ++i) cin >> h[i];

    for(int i = 0; i < m; ++i)
    {
        cin >> from;
        cin >> to;
        edges[from].insert(to);
        edges[to].insert(from);
    }

    for(int i = 1; i <= n; ++i)
    {
        bool higher = true;
        for(auto j : edges[i])
        {
            if(h[i] <= h[j]) higher = false;
        }

        if(higher) res++;
    }

    cout << res << "\n";
    return 0;
}