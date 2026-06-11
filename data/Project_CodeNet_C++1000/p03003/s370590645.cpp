#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <set>
#include <stack>
#include <climits>
#include <cmath>

#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define rep1(i,n) for(int i=1, i##_len=(n); i<=i##_len; ++i)
#define reps(i,s,n) for(int i=s, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
const char sp = ' ';
#define MOD 1000000007

using namespace std;
static ll dp[3000][3000];
int main(void){
    
    ll N, M, S[3000], T[3000];
    cin>>N>>M;
    rep(i, N) cin>>S[i];
    rep(j, M) cin>>T[j];
    MEMSET(dp, 0);
    dp[0][0]=0;
    rep(i, N+1) rep(j, M+1){
        if(i==0 || j==0) dp[i][j]=0;
        else{
        dp[i][j]=(dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+MOD)%MOD;
        if(S[i-1]==T[j-1]) dp[i][j]+=(dp[i-1][j-1]+1)%MOD;
        dp[i][j]%=MOD;
            //cout<<i<<sp<<j<<sp<<dp[i][j]<<endl;
        }
    }
    cout<<(dp[N][M]+1)%MOD<<endl;
    return 0;
}
