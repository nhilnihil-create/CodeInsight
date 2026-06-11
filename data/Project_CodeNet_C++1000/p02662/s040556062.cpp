#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long MOD=998244353;

int main(){
    long long N,S;
    cin >> N >> S;
    long long aa;
    vector<long long> A;
    long long i,j;
    for(i=0; i<N; i++){
        cin >> aa;
        A.push_back(aa);
    }
    sort(A.begin(),A.end());
    long long dp[N+1][S+1];
    for(j=0; j<=S; j++){
        dp[0][j]=0;
    }
    dp[0][0]=1;
    for(i=1; i<=N; i++){
        dp[i][0]=(2*dp[i-1][0])%MOD;
    }
    for(i=1; i<=N; i++){
        for(j=1; j<=S; j++){
            if(j<A[i-1]){
                dp[i][j]=(2*dp[i-1][j])%MOD;
            }else{
                dp[i][j]=(2*dp[i-1][j]+dp[i-1][j-A[i-1]])%MOD;
            }
        }
    }
    cout << dp[N][S] << endl;
    system("pause");
    return 0;
}