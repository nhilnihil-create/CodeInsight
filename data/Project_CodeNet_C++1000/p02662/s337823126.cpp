#include<bits/stdc++.h>

#define rep(i,N) for(int i=0;i<N;i++)
#define rep2(i,N) for(int i=1;i<=N;i++)
using namespace std;
long long  INF=1e18;
long long mod=998244353;

//status unsolved

int main(){
    
    int N,S;
    cin>>N>>S;
    vector<int>A(N);

    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    //dp[i][k]:=最初のi個の数のみについて考えた時の、
    //総和がkであるように選んでできる部分集合全てについての
    //それを含むような集合の個数の総和

    vector<vector<long long>>dp(N+1,vector<long long>(S+1,0));

    dp[0][0]=1;

    for(int i=0;i<N;i++){
        for(int k=0;k<=S;k++){
            //A[i]を選ばない時、和がkになる部分集合自体は変化しないが
            //それを含む集合の個数はA[i]を含むか含まないかの2通りになる
            dp[i+1][k]+=dp[i][k]*2%mod;
            
            //和がk-A[i]のものをたす
            if(k-A[i]>=0)dp[i+1][k]+=dp[i][k-A[i]];
            dp[i+1][k]%=mod;
        }
    }
    cout<<dp[N][S]<<endl;

    return 0;

}
/*


*/
