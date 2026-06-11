#include <bits/stdc++.h>
using namespace std;
#define repr(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
#define mod 1000000007

ll gcd(ll x,ll y) {return y ? gcd(y,x%y) : x;} 
ll lcm(ll x,ll y) {return x/gcd(x,y)*y;}

int main(){
    string s;
    cin >> s;
    int n=s.size();
    const int K=4;
    vector<vector<int>> dp(n+1,vector<int>(K+1,-1));
    dp[0][0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=K;j++){
            if(dp[i][j]==-1) continue;
            for(int k=1;k<=K&&i+k<=n;k++){
                if(j!=k||s.substr(i-j,j)!=s.substr(i,k)){
                    dp[i+k][k]=max(dp[i+k][k],dp[i][j]+1);
                }
            }
        }
    }
    
    int ans=0;
    for(int i=0;i<=K;i++){
        ans=max(ans,dp[n][i]);
    }
    
    cout << ans << endl;
    
    return 0;
}






