#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;

int dp[5005][5005];

int main() {
    int N;
    string S;
    cin >> N >> S;
    for (int i=N-1;i>=0;i--){
        for (int j=N-1;j>=0;j--){
            if (S[i] == S[j]) dp[i][j] = dp[i+1][j+1] + 1;
            else dp[i][j] = 0;
        }
    }
    int ans = 0;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            if (j<i) continue;
            ans = max(ans, min(dp[i][j],j-i));
        }
    }
    cout << ans << endl;
    

    return 0;
}