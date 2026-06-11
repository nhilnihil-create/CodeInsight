#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n,m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> c(m,0);
    for(int i = 0; i < m; i++){
        int b;
        cin >> a[i] >> b;
        for(int j = 0; j < b; j++){
            int ky;
            cin >> ky;
            ky--;
            c[i] += (1<<ky);
        }
    }

    int dp[m+1][1 << n+1];

    for(int i = 0; i <= m; i++){
        for(int j = 0; j < (1<<n+1); j++){
            dp[i][j] = mod;
        }
    }

    for(int i = 0; i <= m; i++) dp[i][0] = 0;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < (1<<n); j++){
            if(j - (c[i]&j) >= 0)
                dp[i+1][j] = min(dp[i][j],dp[i][j-(c[i]&j)]+a[i]);
            //cout << dp[i+1][j] << " " << i << " " << j << endl;
        }
    }

    if(dp[m][(1<<n)-1] == mod) cout << -1 << endl;
    else cout << dp[m][(1<<n)-1] << endl;
}