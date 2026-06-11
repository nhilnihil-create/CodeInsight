#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ii = pair<ll, ll>;

const int MAX { 2010 };

int dist[MAX][MAX];

vector<int> solve(int N, int X, int Y)
{
    for (int u = 1; u <= N; ++u)
        for (int v = u + 1; v <= N; ++v)
            dist[u][v] = min(v - u, abs(u - X) + 1 + abs(v - Y));

    vector<int> ans(N);

    for (int u = 1; u <= N; ++u)
        for (int v = u + 1; v <= N; ++v)
            ans[dist[u][v]]++;

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int N, X, Y;
    cin >> N >> X >> Y;

    auto ans = solve(N, X, Y);

    for (int i = 1; i < N; ++i)
        cout << ans[i] << '\n';

    return 0;
}
