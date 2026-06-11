#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

pair<int, vector<ii>> solve(int N, int K)
{
    set<ii> es;

    for (int u = 1; u <= N; ++u)
        for (int v = u + 1; v <= N; ++v)
            es.insert(ii(u, v));

    int u = 1, v = 2;

    while (K)
    {
        if (v == N)
        {
            ++u;
            v = u + 1;
        }

        if (u >= N - 1)
            break;

        es.erase(ii(u, v));
        ++v;
        --K;
    }

    vector<ii> ans(es.begin(), es.end());

    int M = K > 0 ? -1 : (int) ans.size();

    return make_pair(M, ans);
}

int main()
{
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    auto ans = solve(N, K);
    auto M = ans.first;
    auto xs = ans.second;

    cout << M << endl;

    if (M > -1)
        for (auto x : xs)
            cout << x.first << ' ' << x.second << '\n';

    return 0;
}
