#include <iostream>
#include <math.h>
 
using namespace std;
 
int mod=1e9+7;
int main(){
    int N,M;
    cin >> N >> M;
    int s[N+1];
    for(int i=0;i<=N;i++){
        s[i]=0;
    }
    for(int i=0;i<M;i++){
        int a; cin >> a;
        s[a]=1;
    }
 
    int dp[N+1];
    dp[0]=1;
    for(int i=1;i<N+1;i++){
        dp[i]=0;
    }
    for(int i=0;i<N-1;i++){
        if(s[i]==0){
            dp[i+1]+=dp[i];
            dp[i+2]+=dp[i];
            dp[i+1]%=mod;
            dp[i+2]%=mod;
        }
    }
    if(s[N-1]==0){
            dp[N]+=dp[N-1];
            dp[N]%=mod;
        }
    cout << dp[N]<<endl;
  //cout << dp[2] << endl;
 
}