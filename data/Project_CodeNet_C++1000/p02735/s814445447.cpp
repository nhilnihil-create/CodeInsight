#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

int m[100][100];
int dp[101][101];

int main() {
    int H, W;
    char c;
    cin >> H >> W;
    rep(i, H) {
        rep(j, W) {
            cin >> c;
            m[i][j]  = c == '#' ? 1 : 0;
            dp[i][j] = 0;
        }
    }

    for(int i=1; i<W; ++i) {
        dp[0][i] += dp[0][i-1];
        if(m[0][i-1] == 0 && m[0][i] == 1) {
            dp[0][i]++;
        }
    }

    for(int i=1; i<H; ++i) {
        dp[i][0] += dp[i-1][0];
        if(m[i-1][0] == 0 && m[i][0] == 1) {
            dp[i][0]++;
        }
    }

    for(int i=1; i<H; ++i) {
        for(int j=1; j<W; ++j) {
            int cand1 = dp[i-1][j];
            int cand2 = dp[i][j-1];
            if(m[i-1][j] == 0 && m[i][j] == 1)
                cand1++;
            if(m[i][j-1] == 0 && m[i][j] == 1)
                cand2++;
            dp[i][j] = min(cand1, cand2);
        }
    }

#if 0
    for(int i=0; i<H; ++i) {
        for(int j=0; j<W; ++j) {
            printf("%03d ", dp[i][j]);
        }
        printf("\n");
    }
#endif
    int ret = dp[H-1][W-1];
    if(m[0][0] ==1)
        ret++;
    cout << ret << endl;

    return 0;
}

