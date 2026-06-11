/**
 *    author:  FromDihPout
 *    created: 2020-08-13
**/

#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<vector<int>> cnt(10, vector<int> (10));
    for (int i = 1; i <= n; i++) {
        int first = i, last = i % 10;
        if (last == 0) continue;
        while (first >= 10) {
            first /= 10;
        }
        cnt[first][last]++;
    }
    
    int ans = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            ans += cnt[i][j] * cnt[j][i];
        }
    }
    cout << ans << '\n';
    
    return 0;
}