#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
#define PI 3.141592653589
typedef pair<int,int> PP;
typedef long long ll;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE do { cout << "0" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl

signed main(void){
    int N,M;
    int S[2040],T[2040];
    const int MEM=2040;
    int dp[MEM][MEM]={},sum[MEM][MEM]={};
    cin >> N >> M;
    REP(i,N){
        cin >> S[i];
    }
    REP(i,M){
        cin >> T[i];
    }
    REP(i,N){
        REP(j,M){
            if(i!=0){
                sum[i][j]+=sum[i-1][j];
                sum[i][j]%=MOD;
            }
            if(j!=0){
                sum[i][j]+=sum[i][j-1];
                sum[i][j]%=MOD;
            }
            if(i!=0 && j!=0){
                sum[i][j]-=sum[i-1][j-1];
                sum[i][j]+=MOD;
                sum[i][j]%=MOD;
            }
            dp[i][j]+=sum[i-1][j-1];
            dp[i][j]+=1;
            dp[i][j]%=MOD;
            if(S[i]!=T[j]){
                dp[i][j]=0;
            }
            sum[i][j]+=dp[i][j];
            sum[i][j]%=MOD;
        }
    }
    /*REP(i,N){
        REP(j,M){
            cout << dp[i][j] << " ";
        }cout << endl;
    }cout << endl;
    REP(i,N){
        REP(j,M){
            cout << sum[i][j] << " ";
        }cout << endl;
    }*/
    cout << (sum[N-1][M-1]+1)%MOD << endl;
    return 0;
}

