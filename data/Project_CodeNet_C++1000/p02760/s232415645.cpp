#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    vector<vector<int>> a(3, vector<int>(3));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }
    cin >> n;
    for (int k = 0; k < n; k++)
    {
        int b;
        cin >> b;
        for (int l = 0; l < 3; l++)
        {
            for (int m = 0; m < 3; m++)
            {
                if (a[l][m] == b)
                {
                    a[l][m] = 0;
                }
            }
        }
    }
    if (1)
    {
        for (int x = 0; x < 3; x++) //hori
        {
            if (a[0][x] == 0 && a[1][x] == 0 && a[2][x] == 0)
            {
                cout << "Yes";
                return 0;
            }
        }
        for (int c = 0; c < 3; c++) //vert
        {
            if (a[c][0] == 0 && a[c][1] == 0 && a[c][2] == 0)
            {
                cout << "Yes";
                return 0;
            }
        }
        if (a[0][0] == 0 && a[1][1] == 0 && a[2][2] == 0)
        {
            cout << "Yes";
            return 0;
        }
        if (a[2][0] == 0 && a[1][1] == 0 && a[0][2] == 0)
        {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}