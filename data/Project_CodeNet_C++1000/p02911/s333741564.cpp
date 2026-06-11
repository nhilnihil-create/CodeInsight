#include <bits/stdc++.h>
using namespace std;

const string YES = "Yes";

const string NO = "No";

void solve(int N, int K, int Q, vector<int> A)
{
    vector<int> c(N);
    for (int i = 0; i < Q; i++)
    {
        c.at(A.at(i) - 1)++;
    }
    for (int i = 0; i < N; i++)
    {
        if (Q - c.at(i) < K)
            cout << YES << endl;
        else
            cout << NO << endl;
    }
}

int main()
{
    int N;
    cin >> N;
    int K;
    cin >> K;
    int Q;
    cin >> Q;
    vector<int> A(Q);
    for(int i = 0; i < Q; i++) {
        cin >> A.at(i);
    }
    solve(N, K, Q, move(A));
    return 0;
}
