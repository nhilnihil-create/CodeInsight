#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n + 1), B(n + 1), C(n + 1), D(n + 1), E(n + 1);
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        A[m]++;
    }
    for (int i = 1; i <= n; i++)
    {
        B[A[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        C[i] = C[i - 1] + i * B[i];
        D[i] = D[i - 1] + B[i];
    }
    for (int i = 1; i <= n; i++)
    {
        E[i] = (C[i] + (D[n] - D[i]) * i) / i;
    }
    for (int i = 1, j = n; i <= n; i++)
    {
        for (; j > 0; j--)
        {
            if (E[j] >= i)
            {
                cout << j << endl;
                break;
            }
        }
        if (j == 0)
        {
            cout << j << endl;
        }
    }
}
