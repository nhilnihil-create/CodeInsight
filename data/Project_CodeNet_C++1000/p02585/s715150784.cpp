#include <bits/stdc++.h>
using namespace std;
 
#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define TO_STRING(VariableName) # VariableName
#define LOG(x) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<endl;
#define LOG2(x,y) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<endl;
#define LOG3(x,y,z) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<" "<<TO_STRING(z)<<"="<<z<<endl;
#define LOG4(w,x,y,z) if(DEBUG)cout<<TO_STRING(w)<<"="<<w<<" "<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<" "<<TO_STRING(z)<<"="<<z<<endl;
 
template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
 
int dp[35][5100];
lli score[35][5100];
int P[5100];
int C[5100];
 
void func(int N, int K){
 
    lli ans = -INF;
    REP(i,0,N){
        dp[0][i] = P[i];
        score[0][i] = C[P[i]];
        chmax(ans,score[0][i]);
    }
 
    REP(i,0,33){
        REP(j,0,N){
            dp[i+1][j] = dp[i][dp[i][j]];
            score[i+1][j] = score[i][dp[i][j]]+score[i][j];
        }
    }

    REP(j,0,N){
        lli now = j;
        lli sum = 0;
        REP(k,0,min(30000,K)){
            now = P[now];
            sum += C[now];
            chmax(ans,sum);
        }
    }
 
    REP(j,0,N){
        lli base = K-30000;
        if(base<=0)base = 1;
        
        lli sum = 0;
        int now = j;
        
        REP(k,0,33){
            if(base&(1LL<<k)){
            //now = dp[k][now];
                sum += score[k][now];
                now = dp[k][now];
                
                chmax(ans,sum);
            }
        }
        chmax(ans,sum);
        LOG(base);
        REP(k,base+1,K+1){
            LOG(k);
            
            chmax(ans,sum);
            now = P[now];
            sum += C[now];
            chmax(ans,sum);
        }
    }
    
    cout<<ans<<endl;
 
}
 
int main(){
    // cout << fixed << setprecision(5);
 
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    for(int i = 0 ; i < N ; i++){
        scanf("%d",&P[i]);
        P[i]--;
    }
    for(int i = 0 ; i < N ; i++){
        scanf("%d",&C[i]);
    }
    func(N, K);
    return 0;
}