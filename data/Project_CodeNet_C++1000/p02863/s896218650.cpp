#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const ll mod = 1000000007;
const int inf = 1e9;
const long long INF = 1LL << 60;   // INFの値は1152921504606846976

int dp1[3005][3005];
int dp2[3005][3005];

int main()
{
    int n,t;
    cin >> n >> t;
    int a[n],b[n];
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < t; j++){
            dp1[i][j] = 0;
            dp2[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < t; j++){
            dp1[i+1][j] = dp1[i][j];
            if(j - a[i] >= 0){
                dp1[i+1][j] = max(dp1[i+1][j],dp1[i][j-a[i]] + b[i]);
            }
        }
    }
    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < t; j++){
            dp2[i+1][j] = dp2[i+2][j];
            if(j - a[i] >= 0){
                dp2[i+1][j] = max(dp2[i+1][j],dp2[i+2][j-a[i]] + b[i]);
            }
        }
    }
    int ans = max(dp1[n][t-1],dp2[1][t-1]);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < t; j++){
            ans = max(ans,dp1[i][j] + b[i] + dp2[i+2][t-j-1]);
        }
    }
    cout << ans;
}