#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>

using namespace std;

typedef long long ll;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

int main(void) {
    string S;
    cin >> S;
    const int slen = (int) S.size();

    // dp[i][j]: the last position from position j after 2^i steps
    vector<vector<int>> dp(21, vector<int>(slen));
    for (int i = 0; i < slen; i++) {
        if (S[i] == 'R') {
            dp[0][i] = i + 1;
        } else {
            dp[0][i] = i - 1;
        }
    }

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < slen; j++) {
            dp[i + 1][j] = dp[i][dp[i][j]];
        }
    }

    vector<int> pos(slen, 1);

    // 10^5 = 2^5 + 2 ^7 + 2^9 + 2^10 + 2^15 + 2^16
    vector<int> as = {5, 7, 9, 10, 15, 16};
    for (auto a : as) {
        vector<int> tmp_pos(slen, 0);
        for (int i = 0; i < slen; i++) {
            tmp_pos[dp[a][i]] += pos[i];
        }
        pos = move(tmp_pos);
    }

    vector<int> ans = move(pos);
    cout << ans[0];
    for (int i = 1; i < slen; i++) {
        cout << " " << ans[i];
    }
    cout << endl;

    return 0;
}
