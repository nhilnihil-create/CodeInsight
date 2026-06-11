#include <bits/stdc++.h>
using namespace std;

int h, w, i, j, y, x, k, ans;
char mat[10][10];

int count()
{
    int cnt = 0;
    for (y = 0; y < h; ++y) {
        if ((1 << y) & i)
            continue;

        for (x = 0; x < w; ++x) {
            if ((1 << x) & j)
                continue;

            if (mat[y][x] == '#')
                cnt++;
        }
    }
    return cnt;
}

int main()
{
    cin >> h >> w >> k;
    for (i = 0; i < h; ++i)
        cin >> mat[i];

    for (i = 0; i < (1 << h); ++i) {
        for (j = 0; j < (1 << w); ++j) {
            if (count() == k)
                ans++;
        }
    }
    cout << ans << '\n';
}
