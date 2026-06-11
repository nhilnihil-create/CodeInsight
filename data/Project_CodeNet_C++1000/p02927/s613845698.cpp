#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, d;
    cin >> m >> d;
    int cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            if (j / 10 <= 1 || j % 10 <= 1)
            {
                continue;
            }
            if (i == (j / 10) * (j % 10))
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}