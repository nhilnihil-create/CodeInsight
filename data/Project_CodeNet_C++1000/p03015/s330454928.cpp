#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,vl>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
const ll INF=1LL<<60;
const ll MOD=1000000007;




int main(){
    string S;
    cin >> S;
    ll N=S.size();

    //dp[i][j]について、iは未満フラグ　j桁目までみたとき
    vector<vector<ll>> dp(2, vector<ll>(N, 0));

    dp[0][0]=2;
    dp[1][0]=1;

    for(ll i=1;i<N;i++){
        if(S[i]=='0'){
            dp[0][i]=dp[0][i-1]%MOD;
            dp[1][i]=(dp[1][i-1]*3)%MOD;
        }
        else{
            dp[0][i]=(dp[0][i-1]*2)%MOD;
            dp[1][i]=(dp[1][i-1]*3+dp[0][i-1])%MOD;
        }
    ;}
    
    cout<<(dp[0][N-1]+dp[1][N-1])%MOD<<endl;


    return 0;
}
