#include <bits/stdc++.h>

#define FOR(i, num) for (i = 0; i < num; i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()

using namespace std;

array<array<bool, 100>, 100> status; // y x trueなら黒
array<array<int, 100>, 100> res;

void dfs(int cur_x, int cur_y, int prev_count, bool is_reverse_prev)
{
    // もし前のマスでひっくり返していたら、今回はカウントを上げなくても良い。

    int cur_count = prev_count;
    bool is_reverse = false;
    if (status[cur_y][cur_x])
    {
        // このマスが黒で前回ひっくり返していないとき
        if (!is_reverse_prev)
        {
            // 今回ひっくり返す
            cur_count++;
            is_reverse = true;
        }
        else
        {
            // ひっくり返していたなら連続なのでカウントは上がらない
            is_reverse = true;
        }
    }
    // 最小なら反映して継続
    if (res[cur_y][cur_x] > cur_count)
    {
        res[cur_y][cur_x] = cur_count;

        int next_x = cur_x + 1;
        int next_y = cur_y + 1;
        if (next_x < 100)
        {
            dfs(next_x, cur_y, cur_count, is_reverse);
        }
        if (next_y < 100)
        {
            dfs(cur_x, next_y, cur_count, is_reverse);
        }
    }
}

int main()
{
    int N, M, K, i, k, H, W;

    FOR(i, 100)
    {
        status[i].fill(false);
    }
    FOR(i, 100)
    {
        res[i].fill(10101010);
    }

    cin >> H >> W;

    REP(i, H)
    {
        string input;
        cin >> input;
        REP(k, W)
        {
            status[i][k] = input[k] == '#';
        }
    }

    dfs(0, 0, 0, false);

    cout << res[H - 1][W - 1] << endl;

    return 0;
}