#include <bits/stdc++.h>
using namespace std;
long long dp[1000006][2];
int main(void) {
    ios_base::sync_with_stdio(false);
    string n;
    while (cin >> n) {
        memset(dp,0,sizeof(dp));
        for(int i =0; i < n.size();i++){
            if(i == 0){
                dp[i][0]=n[i]-'0';
                dp[i][1]=(10-(n[i]-'0'))+1;
            }
            else{
                dp[i][0]=min(dp[i-1][0]+n[i]-'0',dp[i-1][1]+n[i]-'0');
                dp[i][1]=min(dp[i-1][0]+(10-(n[i]-'0'))+1,dp[i-1][1]+(10-(n[i]-'0'))-1);
            }
        }
        cout<<min(dp[n.size()-1][0],dp[n.size()-1][1])<<'\n';
    }
}