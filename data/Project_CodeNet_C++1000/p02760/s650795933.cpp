#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    vector<vector<int>> a(3, vector<int>(3));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];
    }
    int n; cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    
    vector<vector<bool>> c(3, vector<bool>(3, false));
    for (int t:b)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (a[i][j] == t) c[i][j] = true;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (c[i][0] && c[i][1] && c[i][2])
        {
            cout << "Yes" << endl;
            return 0;
        }
        if (c[0][i] && c[1][i] && c[2][i])
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    if (c[0][0] && c[1][1] && c[2][2])
    {
        cout << "Yes" << endl;
        return 0;
    }
    if (c[0][2] && c[1][1] && c[2][0])
    {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}