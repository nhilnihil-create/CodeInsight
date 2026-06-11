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
    for (int i = 0; i < K; i++)
    {
        if (n_seg == 1)
            break;
        if (n_seg == 2)
            n_seg -= 1;
        else
            n_seg -= 2;
    }
    cout << N - n_seg << endl;
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
