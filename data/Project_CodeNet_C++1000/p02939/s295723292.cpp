#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()

string S;

const int maxn = 2e5 + 5;
int dp[maxn][3];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> S;
    memset(dp, -1, sizeof(dp));
    dp[1][1] = 1;
    int n = S.length();
    if(n > 1){
        dp[2][2] = 1;
        if(S[0] != S[1]){
            dp[2][1] = 2;
        }
    }
    for(int i = 3;i <= n;i++){
        for(int j = 1;j <= 2;j++){
            int k = i - j;
            string str1 = S.substr(i - j, j);
            for(int l = 1;l <= 2;l++){
                if(dp[k][l] == -1){
                    continue;
                }
                string str = S.substr(k - l, l);
                if(str != str1){
                    dp[i][j] = max(dp[i][j], dp[k][l] + 1);
                }
            }
        }
    }
    cout << max(dp[n][1], dp[n][2]) << endl;
    return 0;
}
