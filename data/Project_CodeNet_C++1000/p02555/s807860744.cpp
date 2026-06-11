//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
//using Graph = vector<vector<int>>;
typedef long long ll;
using Graph = vector<vector<pair<ll,ll>>>;
const int mod =1e+9+7;

const int dy[4]={0,1,0,-1};
const int dx[4]={1,0,-1,0};
const ll INF=1e10;

int main(){
    ll s; cin>>s;
    vector<ll>dp(s+1);
    dp[0]=1;
    dp[1]=0;
    dp[2]=0;
    for(int i=3;i<=s;i++){
        dp[i]=dp[i-1]+dp[i-3];
        dp[i]%=mod;
    }
    cout<<dp[s]<<endl;
    }









