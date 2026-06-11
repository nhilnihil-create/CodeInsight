#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 2006
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
#define SZ(x) int(x.size())
#define OUT(a) cout<<(a)<<endl
#define VECIN(type, c, n) vector<type> c(n);for(auto& i:c) cin>>i;
#define MOD 1000000007
ll dp[N][N];
int main(){
	int n,m;
    cin>>n>>m;
    vector<int> S(n);
    vector<int> T(m);
    REP(i,n){
        cin>>S[i];
    }
    REP(i,m){
        cin>>T[i];
    }
    REP(i,N){
        dp[0][i]=1;
        dp[i][0]=1;
    }
    REP(i,n){
        REP(j,m){
            if(S[i]==T[j]){
                dp[i+1][j+1]=(dp[i+1][j]+dp[i][j+1])%MOD;
            }
            else{
                dp[i+1][j+1]=(dp[i][j+1]+dp[i+1][j]-dp[i][j])%MOD;
            }
        }
    }
    if(dp[n][m]<0) dp[n][m]+=MOD;
    OUT(dp[n][m]);
    return 0;
}