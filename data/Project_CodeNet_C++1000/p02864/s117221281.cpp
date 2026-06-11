#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
typedef signed long long ll;

int64_t H[300+10];

int main() {


    int N=0;
    int K=0;
    ll ans=1LL<<60;
    cin >> N;
    cin >> K;
    if(N==K) {
        std::cout << "0"; 
        return 0;
    }
    ll dp[K+1][N+1];
    
    for(int i=1; i<=N;i++){
        cin >> H[i];
    }
    for(int i=0; i<K+1; i++){
        for(int j=0; j<N+1; j++){
            dp[i][j]=1LL<<60;
        }
    }

    dp[K][0]=0;

    for(int i=0; i<=N; i++){
        for(int j=K; j>=0; j--){
            for(int y=j; y>=0; y--){
                if(i+(K+1)-y>N) continue;
                int diff = H[i+(K+1)-y]-H[i+K-j];
                diff = max(diff,0);
                dp[y][i+(K+1)-y]=min(dp[y][i+(K+1)-y],dp[j][i+K-j]+diff);
                if(i+(K+1)-y>=K-y+(N-K)) ans = min(ans, dp[y][i+(K+1)-y]);
            }
        }
    }
    std::cout << ans;
    return 0;
}
