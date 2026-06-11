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

lli dp[3000][3000];

void func(long long N, std::vector<long long> A){

    vector<pair<lli,lli>> v;
    REP(i,0,N){
        v.push_back({A[i],i+1});
    }

    sort(v.rbegin(),v.rend());

    dp[0][N+1] = 0;
    REP(i,0,N){
        pair<lli,lli> &p = v[i];
        lli nowP = p.first;
        lli nowI = p.second;
        REP(j,0,i+1){
            lli nowL = j;
            lli nowR = N-i+j+1;
            LOG3(i,nowL,nowR);
            chmax(dp[nowL][nowR-1],dp[nowL][nowR]+nowP*abs(nowR-1-nowI));
            chmax(dp[nowL+1][nowR],dp[nowL][nowR]+nowP*abs(nowI-(nowL+1)));
        }
    }

    lli ans = 0;
    REP(i,0,N){
        chmax(ans,dp[i][i+1]);
    }

    cout<<ans<<endl;

}

int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    func(N, std::move(A));
    return 0;
}
