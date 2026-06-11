#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define mod 1000000007
int dp[2*3001][2*3001];
int n,m;
void CommonSubsequence(int *A, int *B) {
    
    memset(dp, 0, sizeof dp);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(A[i-1]==B[j-1]) {
                dp[i][j] = (1 + dp[i-1][j]%mod + dp[i][j-1]%mod)%mod;
            } else {
                dp[i][j] = (dp[i-1][j]%mod+dp[i][j-1]%mod-dp[i-1][j-1]%mod+mod)%mod;
            }
        }
    }    
}

#undef int 
int main(){
#define int long long
    
    cin>>n>>m;
    int s[n], t[m];
    for(int i=0;i<n;i++) cin>>s[i];
    for(int i=0;i<m;i++) cin>>t[i];
    CommonSubsequence(s,t);
    cout<<(dp[n][m]+1)%mod;
    return 0;
}

