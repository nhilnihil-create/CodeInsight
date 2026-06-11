#include <bits/stdc++.h>

#define llint long long int

using namespace std;

int main()
{
    int N;

    cin >> N;

    vector<llint> koutaiwa(N + 1);

    for (int i = 1; i <= N; i++)
    {
        llint A;

        cin >> A;

        if (i % 2 == 1)
        {
            koutaiwa[i] += koutaiwa[i - 1] + A;
        }
        else
        {
            koutaiwa[i] += koutaiwa[i - 1] - A;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        if (i == 1)
        {
            cout << koutaiwa[N] << " ";
        }
        else if (i % 2 == 0)
        {
            cout << 2 * koutaiwa[i - 1] - koutaiwa[N] << " ";
        }
        else
        {
            cout << 2 * (-koutaiwa[i - 1]) + koutaiwa[N] << " ";
        }
        if (i == N)
        {
            cout << endl;
        }
    }
}