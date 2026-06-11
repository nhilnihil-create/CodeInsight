#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1000000007;
const LL LINF=1LL<<60;
const int INF=1<<30;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};


int main(){
    int n,k;cin >> n >> k;
    vector<LL> h(n+1,0);
    for (int i = 0; i < n; i++) {
        cin >> h[i+1];
    }
    vector<vector<vector<LL>>> dp(n+2,vector<vector<LL>> (k+2,vector<LL>(n+2,LINF)));
    dp[0][0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int l = 0; l <= i; l++) {
                dp[i+1][j+1][l] = min(dp[i+1][j+1][l], dp[i][j][l]);
                dp[i+1][j][i] = min(dp[i+1][j][i], dp[i][j][l] + max(0LL,h[i] - h[l]));
            }
        }
    }
    LL ans = LINF;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            ans = min(ans, dp[n+1][i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
