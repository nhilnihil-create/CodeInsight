#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define itn int
#define rep(i,n) for(int i = 0;i < n;i++)
#define P pair<int,int>

ll dp[(1<<13)];

int main(void){
    int n,m;
    cin >> n >> m;
    
    ll a[m],b[m];
    int c[m][n];
    
    for(int i = 0;i < m;i++){
        cin >> a[i] >> b[i];
        for(int j = 0;j < b[i];j++){
            cin >> c[i][j];
            c[i][j]--;
        }
    }
    
    for(int i = 0;i <= (1<<n);i++){
        dp[i] = 1e10;
    }
    
    dp[0] = 0;
    for(int bit = 0;bit <= (1 << n);bit++){
        for(int i = 0;i < m;i++){
            int bit2 = 0;
            for(int j = 0;j < b[i];j++){
                bit2 |= (1 << c[i][j]);
            }
            dp[bit | bit2] = min(dp[bit | bit2],dp[bit] + a[i]);
        }
    }
    if(dp[(1<<n)-1] == 1e10)dp[(1<<n)-1] = -1;
    cout << dp[(1<<n)-1] << endl;
}