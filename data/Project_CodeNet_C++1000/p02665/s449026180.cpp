#include <bits/stdc++.h>
using namespace std;

void solve(int N, vector<int> A)
{
    if (N == 0)
    {
        cout << (A.at(0) == 1 ? 1 : -1) << endl;
        return;
    }

    vector<int64_t> rest(N + 1);
    int64_t acc = 0;
    for (int i = N; i >= 0; i--)
    {
        acc += A.at(i);
        rest.at(i) = acc;
    }

    int64_t res = 1;
    int64_t curr = 1;
    for (int i = 0; i < N; i++)
    {
        if (curr - A.at(i) <= 0)
        {
            cout << -1 << endl;
            return;
        }
        int64_t next = min(2 * (curr - A.at(i)), rest.at(i + 1));
        res += next;
        curr = next;
    }
    cout << (curr == A.at(N) ? res : -1) << endl;
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N + 1);
    for (int i = 0; i < N + 1; i++)
    {
        cin >> A.at(i);
    }
    solve(N, move(A));
    return 0;
}
