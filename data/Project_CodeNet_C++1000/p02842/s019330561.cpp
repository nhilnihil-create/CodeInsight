#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N;
    cin >> N;

    int X = N / 1.08;
    while (X * 1.08 < N)
    {
        X++;
    }

    if ((int)(X * 1.08) == N)
    {
        cout << X << endl;
    }
    else
    {
        cout << ":(" << endl;
    }

    return 0;
}