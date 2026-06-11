#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<int>> Graph; //隣接行列でグラフを表現

int main()
{
    ll N, K;
    cin >> N >> K;

    Graph next_town(60, vector<int>(N));

    for (int v = 0; v < N; v++)
    {
        cin >> next_town[0][v];
        next_town[0][v]--;
    }

    for (int d = 0; d + 1 < 60; d++)
    {
        for (int v = 0; v < N; v++)
            next_town[d + 1][v] = next_town[d][next_town[d][v]];
    }
    int v = 0;
    for (int d = 0; d < 60; ++d)
    {
        if (K & (1LL << d))
            v = next_town[d][v];
    }
    cout << v + 1 << endl;
    return 0;
}