// https://atcoder.jp/contests/abc138/tasks/abc138_d
#include <bits/stdc++.h>
using namespace std;
using children = vector<int>;

void dfs(int i, int p, vector<children> &parents, vector<int64_t> &counter)
{

    for (int c : parents.at(i))
    {
        if (c != p)
        {
            counter[c] += counter[i];
            dfs(c, i, parents, counter);
        }
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<children> parents(n, children());
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        parents.at(a).push_back(b);
        parents.at(b).push_back(a);
    }
    vector<int64_t> counter(n, 0);
    for (int i = 0; i < q; i++)
    {
        int p, x;
        cin >> p >> x;
        counter.at(--p) += x;
    }
    dfs(0, 0, parents, counter);
    for (int64_t l : counter)
    {
        cout << l << " ";
    }
}