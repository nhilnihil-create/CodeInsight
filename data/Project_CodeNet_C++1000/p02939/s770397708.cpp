#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

string s;
ll dp[1000010];

int main(){
    cin>>s;
    dp[0]=1;
    if(s[0]==s[1]){
        dp[1]=1;
        dp[2]=2;
    }
    else{
        dp[1]=2;
        if(s[1]==s[2]) dp[2]=2;
        else dp[2]=3;
    }
    for(int i=3;i<=s.size();i++){
        if(s[i]!=s[i-1]) dp[i]=dp[i-1]+1;
        else dp[i]=dp[i-3]+2;
    }
    cout<<dp[s.size()-1]<<"\n";
    return 0;
}