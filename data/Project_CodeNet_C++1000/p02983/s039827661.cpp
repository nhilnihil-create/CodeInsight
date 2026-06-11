#include <bits/stdc++.h>

#define llint long long int
#define MOD 2019

using namespace std;

int main()
{
    int L, R;

    cin >> L >> R;

    if (R - L > 2 * MOD)
    {
        R = L + 2 * MOD;
    }
    int min = 2019;

    for (int i = L; i <= R; i++)
    {
        for (int j = i + 1; j <= R; j++)
        {
            int val = ((i % MOD) * (j % MOD)) % MOD;

            if (val < min)
            {
                min = val;
            }
        }
    }
    cout << min << endl;
}