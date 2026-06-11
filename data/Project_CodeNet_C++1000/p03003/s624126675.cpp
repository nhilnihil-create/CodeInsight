#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1000000007;

int main(){
    ll N, M;
    cin>>N>>M;
    vector<ll> S(N), T(M);
    for(ll i=0; i<N; i++){
        cin>>S[i];
    }
    for(ll i=0; i<M; i++){
        cin>>T[i];
    }
    vector<vector<ll>> dp(N+1, vector<ll>(M+1, 0));
    for(ll i=0; i<N+1; i++){
        dp[i][0]=1;
    }
    for(int i=0; i<M+1; i++){
        dp[0][i]=1;
    }
    for(ll i=1; i<=N; i++){
        for(ll j=1; j<=M; j++){
            dp[i][j]=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1];
          	dp[i][j]+=MOD;
            dp[i][j]%=MOD;
            if(S[i-1]==T[j-1]){
                dp[i][j]+=dp[i-1][j-1];
              	dp[i][j]+=MOD;
                dp[i][j]%=MOD;
              	//cout<<"!";
            }
          	//cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }
    cout<<dp[N][M]<<endl;
  	return 0;
}