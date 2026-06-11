#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main()
{
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<int> A(Q), B(Q), C(Q), D(Q);
    for (int i = 0; i < Q; i++)
    {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
        A[i]--;
        B[i]--;
    }

    vector<vector<int> > V[11];
    for (int i = 1; i <= M; i++)
    {
        V[1].push_back({i});
    }

    for (int i = 1; i < N; i++)
    {
        for (auto &v : V[i])
        {
            int b = v.back();
            for (int a = b; a <= M; a++)
            {
                auto v2 = v;
                v2.push_back(a);
                V[i + 1].push_back(v2);
            }
        }
    }

    // for (int i = 0; i < 11; i++)
    // {
    //     for (int j = 0; j < V[i].size(); j++)
    //     {
    //         for (int k = 0; k < V[i][j].size(); k++)
    //         {
    //             cout << V[i][j][k] << " ";
    //         }
    //         cout << endl;
    //     }
    // }

    int ans = 0;
    for (auto &v : V[N])
    {
        int res = 0;
        for (int i = 0; i < Q; i++)
            if (v[B[i]] - v[A[i]] == C[i])
                res += D[i];
        ans = max(ans, res);
    }

    cout << ans << endl;
    return 0;
}