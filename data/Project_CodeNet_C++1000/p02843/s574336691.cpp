#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int X;
    cin >> X;
    
    vector<int> yasui = {100, 101, 102, 103, 104, 105};
    vector<int> dp(X + 1, 0);
    dp[0] = 1;
    rep(i, X + 1) rep(j, 6) {
        if (i + yasui[j] <= X) {
            if (dp[i]) dp[i + yasui[j]] = 1;
        }
    }
    cout << dp[X] << endl;
    return 0;
}
