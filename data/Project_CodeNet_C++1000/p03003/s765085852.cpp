#include<cstdio>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<iomanip>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
#define DEBUG(x) cout<<#x<<"="<<x<<endl
#define DEBUG2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
typedef long long ll;
class Solver{
public:
    static const int MAXN=2e3+10;
    static const ll MOD=1e9+7;
    int N,M;
    int S[MAXN],T[MAXN];
    ll dp[MAXN][MAXN];
    ll sum[MAXN][MAXN];
    void solve(){
        ios::sync_with_stdio(false);
        cin>>N>>M;
        dp[0][0]=1;
        sum[0][0]=1;
        for(int u=1;u<=N;u++){
            cin>>S[u];
            sum[u][0]=1;
        }
        for(int u=1;u<=M;u++){
            cin>>T[u];
            sum[0][u]=1;
        }
        for(int u=1;u<=N;u++){
            for(int v=1;v<=M;v++){
                //本身的情况已经考虑进去了,dp[0][0]=1
                if(S[u]==T[v])dp[u][v]=sum[u-1][v-1];
                else dp[u][v]=0;
                sum[u][v]=((sum[u-1][v]+sum[u][v-1])%MOD-sum[u-1][v-1]+MOD+dp[u][v])%MOD;
            }
        }
        cout<<sum[N][M];
    }
};
int main()
{
    // freopen("in.txt","r",stdin);
    (new Solver())->solve();  
}