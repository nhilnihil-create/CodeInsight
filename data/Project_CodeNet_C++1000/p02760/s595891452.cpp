#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int a[3][3];

    rep(i, 3) rep(j, 3) cin >> a[i][j];

    int n;
    cin >> n;

    rep(i, n)
    {
        int b;
        cin >> b;
        rep(j, 3) rep(k, 3) if (a[j][k] == b) a[j][k] = 0;
    }

    bool bingo = false;
    rep(i, 3)
    {
        int r = 0, c = 0;
        rep(j, 3)
        {
            if (a[i][j] == 0)
                c++;
            if (a[j][i] == 0)
                r++;
        }
        if (c == 3 || r == 3)
            bingo = true;
    }

    int l = 0;
    rep(i, 3) if (a[i][i] == 0) l++;
    if (l == 3)
        bingo = true;
    if (a[2][0] == 0 && a[1][1] == 0 && a[2][0] == 0)
        bingo = true;
    if (bingo)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}