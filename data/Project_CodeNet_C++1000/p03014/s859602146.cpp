#include <bits/stdc++.h>
#include <math.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
using Graph = vector<vector<int>>;
typedef long long ll;
typedef pair<int, int> P;

const int MOD = 1000000007;
const int INF_32 = 1LL << 30;
const int64_t INF_64 = 1LL << 60;

int H, W;
void dfs_yoko(int row, int col, vector<vector<char>>& S, vector<vector<int>>& yoko, int& cnt)
{
    if (col >= W || S[row][col] == '#') {
        return;
    } else {
        cnt++;
        dfs_yoko(row, col + 1, S, yoko, cnt);
    }
    yoko[row][col] = cnt;
    return;
}

void dfs_tate(int row, int col, vector<vector<char>>& S, vector<vector<int>>& tate, int& cnt)
{
    if (row >= H || S[row][col] == '#') {
        return;
    } else {
        cnt++;
        dfs_tate(row + 1, col, S, tate, cnt);
    }
    tate[row][col] = cnt;
    return;
}

int main()
{
    cin >> H >> W;
    vector<vector<char>> S(H, vector<char>(W, '.'));
    vector<vector<int>> yoko(H, vector<int>(W, 0));
    vector<vector<int>> tate(H, vector<int>(W, 0));

    rep(row, H)
    {
        rep(col, W)
        {
            cin >> S[row][col];
        }
    }

    rep(row, H)
    {
        rep(col, W)
        {
            if (yoko[row][col] != 0)
                continue;
            int cnt = 0;
            dfs_yoko(row, col, S, yoko, cnt);
        }
    }

    rep(col, W)
    {
        rep(row, H)
        {
            if (tate[row][col] != 0)
                continue;
            int cnt = 0;
            dfs_tate(row, col, S, tate, cnt);
        }
    }

    int ans = 0;
    rep(row, H)
    {
        rep(col, W)
        {
            ans = max(ans, tate[row][col] + yoko[row][col] - 1);
        }
    }

    cout << ans << endl;

    return 0;
}
