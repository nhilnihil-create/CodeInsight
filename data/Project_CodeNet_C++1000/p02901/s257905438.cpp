#include <bits/stdc++.h>
using namespace std;

void solve(int N, int M, vector<int> a, vector<int> b, vector<vector<int>> c)
{
    map<int, int> res;
    for (int i = 0; i < M; i++)
    {
        int si = 0;
        for (int j = 0; j < b.at(i); j++)
        {
            si += 1 << (c.at(i).at(j) - 1);
        }
        for (int sj = 0; sj < (1 << N); sj++)
        {
            if ((si & sj) == sj)
            {
                if (res.count(sj) == 0)
                    res[sj] = a.at(i);
                else
                    res.at(sj) = min(res.at(sj), a.at(i));
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (res.count(1 << i) == 0)
        {
            cout << -1 << endl;
            return;
        }
    }

    for (int si = 1; si < (1 << N); si++)
    {
        if (res.count(si) == 0)
            res[si] = INT_MAX;
        for (int sj = 1; sj < (1 << N); sj++)
        {
            if ((si & sj) == sj)
                res.at(si) = min(res.at(si), res.at(si ^ sj) + res.at(sj));
        }
    }
    cout << res.at((1 << N) - 1) << endl;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> a(M), b(M);
    vector<vector<int>> c(M);
    for (int i = 0; i < M; i++)
    {
        cin >> a.at(i) >> b.at(i);
        c.at(i) = vector<int>(b.at(i));
        for (int j = 0; j < b.at(i); j++)
        {
            cin >> c.at(i).at(j);
        }
    }
    solve(N, M, move(a), move(b), move(c));
    return 0;
}
