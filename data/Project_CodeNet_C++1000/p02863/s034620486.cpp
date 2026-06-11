#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int dp[3005][3005];

int main() {
    int N, T;
    cin >> N >> T;
    vector<pair<int,int>> p(N);
    for (int i=0;i<N;i++){
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(),p.end());
    dp[0][0] = 0;
    int ans = 0;
    for (int i=0;i<N;i++){
        for (int j=0;j<T;j++){
            dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
            int nj = j+p[i].first;
            if (nj < T) dp[i+1][nj] = max(dp[i+1][nj], dp[i][j] + p[i].second);
        }
        int now = dp[i][T-1] + p[i].second;
        ans = max(ans, now);
    }
    cout << ans << endl;

    return 0;
}