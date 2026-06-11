#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

int main () {

    int h, w;

    cin >> h >> w;

    vector<vector<int>> dp(h, vector<int>(w, 99999));
    vector<vector<char>> tile(h, vector<char>(w));

    for(int i = 0; i < h; ++i)
        for(int j = 0; j < w; ++j)
            cin >> tile[i][j];


    if(tile[0][0] == '.')
        dp[0][0] = 0;
    else
        dp[0][0] = 1;

    int di[] = {1, 0};
    int dj[] = {0, 1};

    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            for(int k = 0; k < 2; ++k) {

                int ni = i + di[k], nj = j + dj[k];

                if(ni >= h || nj >= w)
                    continue;

                int add = 0;
                if(tile[i][j] == '.' && tile[ni][nj] == '#')
                    add = 1;

                dp[ni][nj] = min(dp[ni][nj], dp[i][j] + add);

            }
        }
    }

    cout << dp[h - 1][w - 1] << endl;

    return 0;
}