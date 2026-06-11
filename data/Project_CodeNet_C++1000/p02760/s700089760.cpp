#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, b;
    vector<vector<int>> a(3, vector<int>(3));
    vector<vector<bool>> punch(3, vector<bool>(3, false));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (b == a[j][k])
                {
                    punch[j][k] = true;
                }
            }
        }
    }
    if (punch[0][0] * punch[0][1] * punch[0][2] || punch[1][0] * punch[1][1] * punch[1][2] || punch[2][0] * punch[2][1] * punch[2][2] ||
        punch[0][0] * punch[1][0] * punch[2][0] || punch[0][1] * punch[1][1] * punch[2][1] || punch[0][2] * punch[1][2] * punch[2][2] ||
        punch[0][0] * punch[1][1] * punch[2][2] || punch[0][2] * punch[1][1] * punch[2][0])
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}