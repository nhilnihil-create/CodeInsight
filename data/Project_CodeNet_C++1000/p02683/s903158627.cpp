#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int is_succeed(vector<int> Scores, int X)
{
    bool result = true;
    rep(i, Scores.size())
    {
        if (Scores.at(i) < X)
        {
            result = false;
            break;
        }
    }

    return result;
}

int main()
{
    int N, M, X;
    cin >> N >> M >> X;

    vector<int> C(N);
    vector<vector<int>> A(N, vector<int>(M));
    rep(i, N)
    {
        cin >> C.at(i);
        rep(j, M) cin >> A.at(i).at(j);
    }

    int ans = 1e9;
    for (int i = 0; i < (1 << N); i++)
    {
        vector<int> Scores(M, 0);
        int cost = 0;

        bitset<12> bit(i);
        rep(j, N)
        {
            if (bit.test(j))
            {
                cost += C.at(j);
                rep(k, M)
                {
                    Scores.at(k) += A.at(j).at(k);
                }
            }
        }

        if (is_succeed(Scores, X))
        {
            ans = min(ans, cost);
        }
    }

    if (ans == 1e9)
    {
        ans = -1;
    }

    cout << ans << endl;

    return 0;
}