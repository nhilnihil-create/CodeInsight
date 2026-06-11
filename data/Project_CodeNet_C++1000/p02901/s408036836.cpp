#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<long> >dp(m+1,vector<long>(1<<n,1<<30));
    for(int i=0;i<m;i++){
        dp[i][0] = 0;
    }
    vector<pair<long,long> >key(m);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        key[i].second = a;
        key[i].first = 0;
        for(int j=0;j<b;j++){
            int c;
            cin >> c;
            key[i].first += 1<<(c-1);
        }
    }
    
    for(int i=0;i<m;i++){
        for(int j=0;j<(1<<n);j++){
            int jj= j | key[i].first;
            dp[i+1][jj] = min(min(dp[i+1][jj],dp[i][jj]),dp[i][j] + key[i].second);
            dp[i+1][j] = min(dp[i+1][j],dp[i][j]);

        }
    }
    int ans = 1<<30;
    for(int i=1;i<=m;i++){
        ans = min((long)ans,dp[i][(1<<n)-1]);
    }
    if(ans==1<<30)cout<<-1<<endl;
    else cout<<ans<<endl;
    

}