#include <bits/stdc++.h>

#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,n,s) for(int i=(s);i<(n);i++)
#define rrep(i,n) for(int i=(n-1);i>=0;i--)
#define rreps(i,n,s) for(int i=s;i>=n;i--)
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

using ll = long long;
using namespace std;
constexpr long long MAX = 5100000;
constexpr long long INF = 1LL << 60;
constexpr int MOD = 1000000007;

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
string s;
cin>>s;
int n=s.size();
int dp[n][2];
dp[0][0]=1;
dp[0][1]=0;
dp[1][0]=s[1]!=s[0]?2:1;
dp[1][1]=1;

reps(i,n-1,1){
    int dp_0 = s[i+1]!=s[i]?1:0;
    dp[i+1][0]=max(dp[i][0]+dp_0,dp[i][1]+1);
    
    if(i+1>3){
        string s1=s.substr(i-1,2);
        string s2=s.substr(i-3,2);
        int dp_1= s1!= s2?1:0;
        dp[i+1][1]=max(dp[i-1][0]+1,dp[i-1][1]+dp_1);
    }
    else{
        dp[i+1][1]=dp[i-1][0]+1;
    }
}
cout<<max(dp[n-1][0],dp[n-1][1])<<endl;
return 0;
}