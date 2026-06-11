#include <bits/stdc++.h>

using namespace std;

int parent[200005];
int ranking[200005];
int n, m;

int get_parent(int a)
{
    return (parent[a] = parent[a] == a ? a : get_parent(parent[a]));
}

void join(int a, int b)
{
    if (get_parent(a) == get_parent(b))
        return;
    if (ranking[get_parent(a)] < ranking[get_parent(b)])
        swap(a,b);
    ranking[get_parent(a)] += ranking[get_parent(b)];
    parent[get_parent(b)] = parent[get_parent(a)];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        ranking[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        join(a,b);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, ranking[i]);
    }

    cout << ans << endl;
    return 0;
}