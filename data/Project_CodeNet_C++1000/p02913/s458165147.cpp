#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int dp[5005][5005];

int main(){
    int n;
    string s;
    cin>>n>>s;
    for(int i=n-2; i>=0; --i){
        for(int j=n-1; j>=i+1; --j){
            if(s[i]==s[j])dp[i][j]=dp[i+1][j+1]+1;
            else dp[i][j]=0;
        }
    }
    int ans=0;
    rep(i,n)rep(j,n)ans=max(ans,min(dp[i][j],j-i));
    cout<<ans<<endl;
}