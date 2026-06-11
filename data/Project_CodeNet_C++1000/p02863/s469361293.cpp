#include <bits/stdc++.h>
using namespace std;

int n,t;
typedef pair <int,int> P;

int res = 0;
int dp[3005][3005];
int main(){
    cin >> n >> t;
    vector<P> p(n);
    for(int i = 0;i<n;i++){
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(),p.end());
    for(int i = 0;i<n;i++){
        for(int j = 0;j<t;j++){
            dp[i+1][j] = max(dp[i][j],dp[i+1][j]);
            int tmp = j + p[i].first;
            if(tmp < t) dp[i+1][tmp] = max(dp[i+1][tmp],dp[i][j] + p[i].second);
        }
        res = max(res,dp[i][t-1] + p[i].second);
    }
    cout << res << endl;
    return 0;
}