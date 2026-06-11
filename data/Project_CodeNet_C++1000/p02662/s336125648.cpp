#include <cstdio>
#include <vector>

using namespace std;

const int MAXN=3e3+5;
typedef long long int ll;
const ll MOD=998244353;
ll dp[MAXN][MAXN];

int N,S;
int A[MAXN];

int main(){
    scanf("%d%d",&N,&S);

    for(int i=0;i<N;i++) scanf("%d",A+i);

    dp[0][0]=1ll;

    for(int i=0;i<N;i++){
        for(int cost=0;cost<=S;cost++){
            int incr[]={A[i],0,0};
            for(int k=0;k<3;k++){
                auto target=cost+incr[k];
                if (target>S) continue;
                dp[i+1][target]=(dp[i+1][target]+dp[i][cost])%MOD;
            }
        }
    }

    printf("%lld\n",dp[N][S]);

    return 0;
}