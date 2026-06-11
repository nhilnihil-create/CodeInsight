#include <bits/stdc++.h>

#define llint long long int

using namespace std;

int main()
{
    int N;

    cin >> N;

    vector<int> a(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }
    vector<vector<int>> yakusu(N + 1, vector<int>());

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; i * j <= N; j++)
        {
            yakusu[i * j].push_back(i);
        }
    }
    vector<int> guki(N + 1, 0), ans(N + 1, 0);

    for (int i = N; i >= 1; i--)
    {
        if ((guki[i] + a[i]) % 2 == 1)
        {
            ans[i] = 1;

            for (int j = 0; j < yakusu[i].size(); j++)
            {
                guki[yakusu[i][j]] = 1 - guki[yakusu[i][j]];
            }
        }
    }
    int M = 0;

    for (int i = 1; i <= N; i++)
    {
        if (ans[i] == 1)
        {
            M++;
        }
    }
    cout << M << endl;

    for (int i = 1; i <= N; i++)
    {
        if (ans[i] == 1)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}