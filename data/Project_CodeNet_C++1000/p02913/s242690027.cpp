#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n;cin>>n;
    string s;cin>>s;
    int dp[n+1][n+1];
    rep(i,n+1)rep(j,n+1) dp[i][j]=0;
    rep(i,n){
        rep(j,i){
            if(s[i]!=s[j])continue;
            if(i-dp[i][j]<=j)continue;
            chmax(dp[i+1][j+1],dp[i][j]+1);
        }
    }
    int res=0;
    rep(i,n+1)rep(j,n+1)chmax(res,dp[i][j]);
    cout<<res<<endl;
}