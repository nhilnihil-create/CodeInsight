#include <bits/stdc++.h>
using namespace std;

void solve(int N, int M, vector<int> A, vector<int> B)
{
    vector<vector<int>> w(M);
    for (int i = 0; i < N; i++)
    {
        if (A.at(i) > M)
            continue;
        w.at(A.at(i) - 1).push_back(B.at(i));
    }

    int res = 0;
    priority_queue<int> q;
    for (int i = 0; i < M; i++)
    {
        for (auto r : w.at(i))
            q.push(r);

        if (q.empty())
            continue;
        res += q.top();
        q.pop();
    }
    cout << res << endl;
}

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A.at(i) >> B.at(i);
    }
    solve(N, M, move(A), move(B));
    return 0;
}
