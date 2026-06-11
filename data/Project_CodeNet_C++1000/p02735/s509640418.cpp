#include <cstdio>
#include <set>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

#define ll long long
const ll N = 1000000000;

int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<int> > ar(h), dp(h);
    for (int i = 0; i < h; ++i) {
        dp[i].resize(w, N);
        for (int j = 0; j < w; ++j) {
            char c; cin >> c;
            dp[i][j] = c == '.' ? 0 : 1;
        }
    }

    for (int i = 0; i < h; ++i) {
        ar[i].resize(w, N);
        for (int j=0;j<w;++j) {
            if (i + j == 0) ar[i][j] = dp[i][j];
            else {
                if (i) {
                    int c = dp[i - 1][j] != dp[i][j] && dp[i][j];
                    ar[i][j] = min(ar[i-1][j] + c, ar[i][j]);
                }
                if (j) {
                    int c = dp[i][j - 1] != dp[i][j] && dp[i][j];
                    ar[i][j] = min(ar[i][j-1] + c, ar[i][j]);
                }
            }
        }
    }

    cout << ar[h - 1][w - 1];
    return 0;
}
