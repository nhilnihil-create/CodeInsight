#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 2000000001;
constexpr ll INF= 9 * 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

ll dp[1000010][2]; //dp[i][j] = i桁目まで決め打った時に条件を満たすものの通り数、ただしj = 0の時はi桁目まで決め打った時にLと一緒、j = 1の時はそれ未満

int main() {
    string S;
    cin >> S;
    dp[1][0] = 2;
    dp[1][1] = 1;
    for(int i = 1;i < S.size();i++) {
        if(S.at(i) == '0') {
            dp[i + 1][0] = dp[i][0];
            dp[i + 1][1] = dp[i][1] * 3 % MOD;
        }
        else {
            dp[i + 1][0] = dp[i][0] * 2 % MOD;
            dp[i + 1][1] = (dp[i][1] * 3 + dp[i][0]) % MOD;
        }
    }
    cout << (dp[S.size()][0] + dp[S.size()][1]) % MOD << endl;
}