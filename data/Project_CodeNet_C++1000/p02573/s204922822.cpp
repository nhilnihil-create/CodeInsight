#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int getParent(vector<int> &parent, int x)
{
    if (parent[x] < 0)
        return x;
    return parent[x] = getParent(parent, parent[x]);
}

void uniteParent(vector<int> &parent, int a, int b)
{
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a == b)
        return;
    if (a > b)
        swap(a, b);
    // 항상 a < b
    parent[a] += parent[b];
    parent[b] = a;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> parent(n + 1, -1);

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        uniteParent(parent, a, b);
    }

    int cnt = 0;
    for (int i = 1; i < n + 1; i++)
    {
        cnt = max(cnt, -parent[i]);
    }
    cout << cnt;

    return 0;
}