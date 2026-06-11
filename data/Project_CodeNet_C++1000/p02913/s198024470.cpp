#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long; 
using P=pair<int,int>;
using lP=pair<ll,ll>;
using fP=pair<double,double>;

int dp[5010][5010]={};
int main(){
    int n;
    string s;
    cin>>n;
    cin>>s;
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(s[i]==s[j]){
                if(i==n-1||j==n-1)dp[i][j]=1;
                else dp[i][j]=min(abs(i-j),dp[i+1][j+1]+1);
            }
            else dp[i][j]=0;
        }
    }
    int ans=0;
    rep(i,n)rep(j,n){
        if(i==j)continue;
        //cout<<dp[i][j];
        //if(j==n-1)cout<<endl;
        ans=max(ans,dp[i][j]);
    }
    cout<<ans<<endl;
    return 0;
}