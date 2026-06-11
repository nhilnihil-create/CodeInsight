#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll maxINT = 1000000000000000000;

int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N;
    cin >> N;
    vector<pair<ll,ll>> v(N+1);
    for(int i = 1 ; i < N+1; ++i){
        ll a;
        cin >> a;
        v[i] = make_pair(a, i);
    }
    sort(v.begin(), v.end(), greater<pair<ll,ll>>());
    vector<vector<ll>> dp(N+1, vector<ll>(N+1));

    for(int i = 1; i < N+1 ; ++i){
        dp[i][0] = dp[i-1][0] + v[i-1].first * abs(v[i-1].second - N + (i-1));
        for(int j = 1 ; j <= i-1 ; ++j){
            dp[i][j] = max(dp[i-1][j] + v[i-1].first * abs(v[i-1].second - N + i - j - 1), dp[i-1][j-1] + v[i-1].first * abs(v[i-1].second - j));
        }
        dp[i][i] = dp[i-1][i-1] + v[i-1].first * abs(v[i-1].second - i);
    }
    ll ret = 0;
    for(int i = 0; i < N+1; ++i){
        ret = max(ret, dp[N][i]);
    }
    cout << ret << endl;

    return 0;


}