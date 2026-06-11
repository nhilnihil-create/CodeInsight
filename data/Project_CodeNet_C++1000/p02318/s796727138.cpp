// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_E
// Wikipedia(ja) solution
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
        string s1, s2;
        cin >> s1 >> s2;
        int n1 = s1.size(), n2 = s2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1));
        for (int i = 0; i <= n1; i++)
                dp[i][0] = i;
        for (int i = 0; i <= n2; i++)
                dp[0][i] = i;
        for (int i = 1; i <= n1; i++) {
                for (int j = 1; j <= n2; j++) {
                        int c = dp[i-1][j-1];
                        c += s1[i-1] == s2[j-1] ? 0 : 1;
                        c = min(c, dp[i-1][j] + 1);
                        c = min(c, dp[i][j-1] + 1);
                        dp[i][j] = c;
                }
        }
        cout << dp[n1][n2] << endl;
        return 0;
}