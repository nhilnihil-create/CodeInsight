#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define fi first
#define se second

template<typename T>
void selfmax(T &a, T b){
    if(b>a) a=b;
}

int n;

int main(){
    //
    //freopen("input.txt", "r", stdin);
    //
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;
    vector<pair<int,int>> a(n);
    for (int i=0; i<n; ++i){
        cin>>a[i].first;
        a[i].second=i;
    }
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, -1));
    dp[0][0]=0;
    sort(a.begin(), a.end(), greater<>());
    for (int i=0; i<n; ++i){
        int val = a[i].fi;
        for (int j=0; j<=i; ++j){
            ll leftDist = abs(a[i].se-j); 
            ll rightDist = abs(n-1-a[i].se-(i-j));
            ll leftScore = val*leftDist;
            ll rightScore = val*rightDist;
            selfmax(dp[i+1][j], dp[i][j] + rightScore);
            selfmax(dp[i+1][j+1], dp[i][j] + leftScore);
        }
    }
    ll ans = 0;
    for (int i=0; i<=n; ++i){
        selfmax(ans, dp[n][i]);
    }
    cout<<ans;
    return 0;
}
