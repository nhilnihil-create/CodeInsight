#include<bits/stdc++.h>
using namespace std;

const long int mod = 1e9+7;
long int dp[100005][2];

int main(){
    string S;
    cin >> S;
    int i,j;
    int L=S.length();
    dp[0][0]=1;
    dp[0][1]=2;
    for(i=0;i<L-1;i++){
        dp[i+1][0]=(dp[i][0]*3)%mod;
        if(S[i+1]=='1'){
            dp[i+1][1]=(dp[i][1]*2)%mod;
            dp[i+1][0]=(dp[i+1][0]+dp[i][1])%mod;
        }
        else dp[i+1][1]=dp[i][1];
    }
    cout << (dp[L-1][0]+dp[L-1][1])%mod << endl;
}