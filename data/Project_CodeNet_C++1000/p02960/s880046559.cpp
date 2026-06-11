//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    string s; cin>>s;
    ll n=s.size();
    vector<vector<ll>> dp(n+1,vector<ll>(13,0));
    dp[0][0]=1;
    rep(i,n){
        if(s[i]!='?'){
            rep(j,13){
                dp[i+1][(j*10+(s[i]-'0'))%13]+=dp[i][j];
                dp[i+1][(j*10+(s[i]-'0'))%13]%=MOD;
            }
        }
        else{
            rep(j,13)rep(k,10){
                dp[i+1][(j*10+k)%13]+=dp[i][j];
                dp[i+1][(j*10+k)%13]%=MOD;
            }
        }
    }
    cout<<(MOD+dp[n][5])%MOD<<endl;
}