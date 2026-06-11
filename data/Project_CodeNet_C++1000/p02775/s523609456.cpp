#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

string s;
int n;
ll dp[1000005][2];
int main(){
    cin>>s;
    n=s.size();
    reverse(s.begin(),s.end());
    memset(dp,0x3f,sizeof(dp));
    dp[0][0]=0;
    rep(i,n)rep(j,2){
        dp[i+1][0]=min(dp[i+1][0],dp[i][j]+(s[i]-'0')+j);
        dp[i+1][1]=min(dp[i+1][1],dp[i][j]+10-(s[i]-'0')-j);
    }
    cout<<min(dp[n][0],dp[n][1]+1)<<endl;
    return 0;
}