#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    vector<vector<ll>> dp(N+1, vector<ll>(N+1, 0ll));
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        A[i] = make_pair(a, i);
    }
    sort(A.begin(), A.end());
    for(int total=1;total<=N;total++){
        for(int r=0;r<=total;r++){
            int l = total - r;
            int i = N - total;
            ll to_r = r-1<0 ? -1 : dp[r-1][l] + ll(abs(A[i].second - r+1))*ll(A[i].first);
            ll to_l = l-1<0 ? -1 : dp[r][l-1] + ll(abs(A[i].second - (N-1-l+1)))*ll(A[i].first);
            dp[r][l] = max(to_l, to_r);
        }
    }
    ll ans = 0;
    for(int r=0;r<=N;r++){
        int l = N - r;
        ans = max(ans, dp[r][l]);
    }
    cout << ans << endl;
    return 0;
}