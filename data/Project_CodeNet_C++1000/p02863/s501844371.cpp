#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include <set>

#define DIV 1000000007
using namespace std;
using ll = long long;

bool cmp(const pair<ll, ll>& p, const pair<ll, ll>& q) {
    if (p.first != q.first)
        return p.first < q.first;
    else
        return p.second > q.second;
}
int main() {
    int N, T;
    cin >> N >> T;

    vector<pair<ll,ll>> food(N);
    for (int i = 0; i < N; i++)
        cin >> food[i].first>>food[i].second;
    sort(food.begin(), food.end(),cmp);

    vector<vector<ll>> dp(N + 1, vector<ll>(T + 1,-1));   
    dp[0][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= T; j++) {
            if (dp[i][j] == -1) continue;
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (j != T) {
                if (j + food[i].first < T)
                    dp[i + 1][j + food[i].first] = max(dp[i + 1][j + food[i].first], dp[i][j] + food[i].second);
                else
                    dp[i + 1][T] = max(dp[i + 1][T], dp[i][j] + food[i].second);
            }
        }
    }

   // cout << "sorted" << endl;
    /*
    for (int i = 0; i < N; i++) {
        cout << food[i].first << " " << food[i].second << endl;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= T; j++) {
            if (dp[i][j] == -1) continue;
            printf("dp[%d][%d]=%lld ", i, j, dp[i][j]);
        }
        cout << endl;
    }
    */
    ll ans = 0;
    for (int i = 0; i <= T; i++)
        ans = max(ans, dp[N][i]);

    cout << ans << endl;

}