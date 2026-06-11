#include <bits/stdc++.h>
using namespace std;

void solve(int N, int K)
{
    if (K > (N - 1) * (N - 2) / 2)
    {
        cout << -1 << endl;
        return;
    }
    int M = (N - 1) + ((N - 1) * (N - 2) / 2 - K);
    cout << M << endl;
    for (int i = 2; i <= N; i++)
    {
        cout << 1 << " " << i << endl;
        M--;
    }
    for (int i = 2; i <= N; i++)
    {
        if (M == 0)
            break;
        for (int j = i + 1; j <= N; j++)
        {
            if (M == 0)
                break;
            cout << i << " " << j << endl;
            M--;
        }
    }
}

int main()
{
    int N, K;
    cin >> N >> K;
    solve(N, K);
    return 0;
}
