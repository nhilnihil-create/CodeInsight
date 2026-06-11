#include <iostream>
#include <vector>
#include <string>
using namespace std;
void chmax(int &a, int b) { if (a < b) a = b; }

int main() {
    int N; string S; cin >> N >> S;

    int res = 0;
    vector<vector<int> > dp(N+1, vector<int>(N+1, 0));
    for (int i = N-1; i >= 0; --i) {
        for (int j = N-1; j > i; --j) {
            if (S[i] == S[j]) chmax(dp[i][j], dp[i+1][j+1] + 1);
            chmax(res, min(dp[i][j], j-i));
        }
    }
    cout << res << endl;
}