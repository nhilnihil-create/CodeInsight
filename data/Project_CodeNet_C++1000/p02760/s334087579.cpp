// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
// #include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
// using namespace atcoder;
using ll = long long;
const int mod = 1e9 + 7;

void solve()
{
    vector<vector<int>> bingo(3, vector<int>(3));
    rep(i, 3) rep(j, 3) cin >> bingo[i][j];
    int n;
    cin >> n;
    vector<vector<bool>> chk(3, vector<bool>(3));
    rep(i, n)
    {
        int b;
        cin >> b;
        rep(j, 3) rep(k, 3)
        {
            if (bingo[j][k] == b)
                chk[j][k] = true;
        }
    }
    bool ok = false;
    if (chk[0][0] && chk[0][1] && chk[0][2])
        ok = true;
    if (chk[1][0] && chk[1][1] && chk[1][2])
        ok = true;
    if (chk[2][0] && chk[2][1] && chk[2][2])
        ok = true;
    if (chk[0][0] && chk[1][0] && chk[2][0])
        ok = true;
    if (chk[0][1] && chk[1][1] && chk[2][1])
        ok = true;
    if (chk[0][2] && chk[1][2] && chk[2][2])
        ok = true;
    if (chk[0][0] && chk[1][1] && chk[2][2])
        ok = true;
    if (chk[0][2] && chk[1][1] && chk[2][0])
        ok = true;
    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main()
{
    // srand((unsigned)time(NULL));
    // int t = clock();
    solve();
    // double et = 1.0 * (clock() - t) / CLOCKS_PER_SEC;
    // printf("Execution Time: %.4lf sec\n", et);
    return 0;
}