//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
const double PI=3.14159265358979323846;
const in MOD = 1000000007ll;
const in INF=1e18+7;
const int inf=1e9+7;
using P=pair<int,int>;
vector<int> dx={0,1,-1,0};
vector<int> dy={1,0,0,-1};


int main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cout << fixed << setprecision(10);
    string s;
    cin>>s;
    int n=s.size();
    vector<vector<vector<in>>> dp(n,vector<vector<in>>(2,vector<in>(2,0ll)));
    dp[0][0][0]=0ll;
    dp[0][0][1]=1ll;
    dp[0][1][0]=2ll;
    dp[0][1][1]=0ll;

    REP(i,1,n){
        if(s[i]=='1'){
            dp[i][0][0]=0ll;
            dp[i][0][1]=dp[i-1][0][0]+dp[i-1][0][1]+dp[i-1][1][0]+dp[i-1][1][1];
                dp[i][0][1] %=MOD;
            dp[i][1][0]=dp[i-1][0][0]*2ll+dp[i-1][1][0]*2ll;
                dp[i][1][0] %= MOD;
            dp[i][1][1]=dp[i-1][0][1]*2ll+dp[i-1][1][1]*2ll;
                dp[i][1][1] %= MOD;
        }
        else{
            dp[i][0][0]=dp[i-1][0][0]+dp[i-1][1][0];
                dp[i][0][0] %= MOD;
            dp[i][0][1]=dp[i-1][0][1]+dp[i-1][1][1];
                dp[i][0][1] %= MOD;
            dp[i][1][0]=0ll;
            dp[i][1][1]=dp[i-1][0][1]*2ll+dp[i-1][1][1]*2ll;
                dp[i][1][1] %=MOD;
        }
    }
    in ans=dp[n-1][0][0]+dp[n-1][0][1]+dp[n-1][1][0]+dp[n-1][1][1];
    ans %= MOD;
    cout<<ans<<endl;
   // rep(i,2)rep(j,2)cout<<i<<" "<<j<<" "<<dp[n-1][i][j]<<endl;
}/*
./problem.exe
*/