#include <iostream>
#include <cstring>

#define rep(i,n) for(int i=0;i<n;i++)
#define mod(i) (i)%2
#define INF (1e9)

using namespace std;

int main()
{
    int H,N,A[10010],B[10010],dp[2][10010];
    //dp[mod(i)][h]:i番目までの魔法を使ってh以上のダメージ与えるのにかかる最小魔力
    //memset(dp,0,sizeof(dp));
    rep(i,2){rep(h,10010){dp[i][h]=INF;}}
    dp[0][0]=0;
    dp[1][0]=0;
    cin>>H>>N;
    rep(i,N){
        cin>>A[i]>>B[i];
    }

    //dp
    rep(i,N){
        rep(h,H+1){
            if(h>=A[i]){
                dp[mod(i+1)][h] = min(dp[mod(i)][h], dp[mod(i+1)][h-A[i]]+B[i]);
            }else{
                dp[mod(i+1)][h] = min(dp[mod(i)][h],B[i]);
            }
        }
    }

    cout << dp[mod(N)][H] << endl;
    
    return 0;
}