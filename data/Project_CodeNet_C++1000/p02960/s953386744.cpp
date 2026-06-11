#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

static const long long MOD=1e9+7;

int main(){
    string s;
    cin>>s;
    int n=s.size();
    vector<vector<long long>> dp(100005,vector<long long>(13,0));
    dp[0][0]=1;
    for(int i=0;i<n;++i){
        for(int j=0;j<13;++j){
            if(s[i]=='?'){
                for(int k=0;k<10;++k){
                    int j2=(10*j+k)%13;
                    dp[i+1][j2]=(dp[i+1][j2]+dp[i][j])%MOD;
                }
            }
            else{
                int k=s[i]-'0';
                int j2=(10*j+k)%13;
                dp[i+1][j2]=(dp[i+1][j2]+dp[i][j])%MOD;
            }
        }
    }

    cout<<dp[n][5]<<endl;
}