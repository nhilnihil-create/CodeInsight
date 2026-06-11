#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <cmath>
#include <cstdio>

using namespace std;

typedef long long ll;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)

int H, W;
char s[100][100];
int score[100][100];

int dfs(int h, int w)
{
    if (h == H - 1 && w == W - 1) {
        score[h][w] = 0;
        return 0;
    }
    else if (score[h][w] != -1) {
        return score[h][w];
    }
    else {
        int s1 = 100000, s2 = 100000;
        if (h < H - 1) {
            if (s[h][w] == '.' && s[h + 1][w] == '#') s1 = 1;
            else s1 = 0;
            s1 += dfs(h + 1, w);
        }
        if (w < W - 1) {
            if (s[h][w] == '.' && s[h][w + 1] == '#') s2 = 1;
            else s2 = 0;
            s2 += dfs(h, w + 1);
        }
        score[h][w] = min(s1, s2);
        return score[h][w];
    }
}

int main(int argc, char **argv)
{
    cin >> H >> W;
    REP(i, H) REP(j, W) cin >> s[i][j];

    REP(i, H) REP(j, W) score[i][j] = -1;

    int a = (s[0][0] == '.')? 0 : 1;
    cout << a + dfs(0, 0) << endl;
    return 0;
}
