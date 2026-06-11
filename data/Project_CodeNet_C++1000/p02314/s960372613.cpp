#include <iostream>
#include <ios>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    int n = 0;
    int m = 0;
    cin >> n >> m;
    vector<int> dp(n + 1, n + 1);
    dp[0] = 0;
    vector<int> ds(m, 0);
    for (auto & di : ds) cin >> di;
    for (auto di : ds){
        if (di > n) continue;
        for (int i = di; i != n + 1; ++i){
            dp[i] = min(dp[i], dp[i - di] + 1);
        }
    }
    cout << dp[n] << endl;
    return 0;
}