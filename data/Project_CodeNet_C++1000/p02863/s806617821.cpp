#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int dp[3005][3005];

int main() {
    int N, T; cin >> N >> T;
    vector<P> sushi(N);
    rep(i, N){
        cin >> sushi[i].first >> sushi[i].second;
    }
    sort(sushi.begin(), sushi.end());

    rep(i, N){
        rep(j, T){
            dp[i+1][j] = dp[i][j];
            if(j-sushi[i].first >= 0 && j-sushi[i].first < T){
                dp[i+1][j] = max(dp[i+1][j], dp[i][j-sushi[i].first] + sushi[i].second);
            }
        }
    }

    int ans = 0;
    rep(i, N){
        ans = max(ans, dp[i][T-1] + sushi[i].second);
    }

    cout << ans << endl;

    return 0;
}