#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const ll mod = 1000000007;
const int inf = 1e9;
const long long INF = 1LL << 60;   // INFの値は1152921504606846976

int main()
{
    int n,t;
    cin >> n >> t;
    vector<P> v;
    
    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end());
    int dp[n+1][t];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < t; j++){
            dp[i][j] = 0;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < t; j++){
            dp[i+1][j] = dp[i][j];
            ans = max(ans,dp[i+1][j] + v[i].second);
            if(j - v[i].first >= 0){
                dp[i+1][j] = max(dp[i+1][j],dp[i][j-v[i].first] + v[i].second);
            }
        }
    }
    cout << ans;
}