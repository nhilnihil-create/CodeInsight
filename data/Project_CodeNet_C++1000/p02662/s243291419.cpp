#include <iostream>
#include <string>
#include <vector>
using ll=long long;
using namespace std;

int main(){
    int N,S;
    cin>>N>>S;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }

    ll mod=998244353;
    vector<vector<ll>> dp(N+1,vector<ll>(S+1,0));
    dp[0][0]=1;
    for(int i=1;i<=N;i++){
        for(int j=0;j<=S;j++){
            dp[i][j]=(dp[i-1][j]*2)%mod;
            if(j>=A[i-1]){
                dp[i][j]+=dp[i-1][j-A[i-1]];
                dp[i][j]%=mod;
            }
        }
    }
/*
    for(int i=0;i<=N;i++){
        for(int j=0;j<=S;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    //*/

    cout<<dp[N][S]<<endl;

    return 0;
}