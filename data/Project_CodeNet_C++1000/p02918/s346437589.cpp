#include <bits/stdc++.h>
using namespace std;

void solve(int N, int K, string S)
{
    int n_seg = 1;
    char prev = S.at(0);
    for (int i = 1; i < N; i++)
    {
        if (prev != S.at(i))
        {
            n_seg++;
            prev = S.at(i);
        }
    }
    int res = min(N - 1, N - (n_seg - 2 * K));
    cout << res << endl;
}

int main()
{
    int N;
    cin >> N;
    int K;
    cin >> K;
    string S;
    cin >> S;
    solve(N, K, S);
    return 0;
}
