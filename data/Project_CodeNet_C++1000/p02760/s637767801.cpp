#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    vector<vector<int>> a(3, vector<int>(3));
    rep(i, 3) rep(j, 3) cin >> a[i][j];
    int n;
    cin >> n;
    vector<int> b(n);
    rep(i, n) cin >> b[i];
    rep(i, n) rep(j, 3) rep(k, 3)
    {
        if (b[i] == a[j][k])
            a[j][k] = 0;
    }
    rep(i, 3)
    {
        bool bingo = true;
        rep(j, 3)
        {
            if (a[i][j] != 0)
                bingo = false;
        }
        if (bingo)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    rep(i, 3)
    {
        bool bingo = true;
        rep(j, 3)
        {
            if (a[j][i] != 0)
                bingo = false;
        }
        if (bingo)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    if (a[0][0] == 0 && a[1][1] == 0 && a[2][2] == 0)
    {
        cout << "Yes" << endl;
        return 0;
    }
    if (a[2][0] == 0 && a[1][1] == 0 && a[0][2] == 0)
    {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}