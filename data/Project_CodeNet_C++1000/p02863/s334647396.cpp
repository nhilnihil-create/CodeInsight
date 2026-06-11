#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)

lli dp[7000];
bool vis[7000];

void func(long long N, long long T, std::vector<long long> A, std::vector<long long> B){
    vis[0]=true;
    vector<pair<lli,lli>> D(N);
    REP(i,0,N)D[i]=mp(A[i],B[i]);
    sort(D.begin(),D.end());
    REP(i,0,N){
        for(lli j=T-1;j>=0;j--){
            dp[j+D[i].first] = max(dp[j+D[i].first],dp[j]+D[i].second);
        }
    }
    lli ans = 0;
    REP(i,0,7000)ans = max(ans,dp[i]);

    cout<<ans<<endl;
}

int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    long long T;
    scanf("%lld",&T);
    std::vector<long long> A(N);
    std::vector<long long> B(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
        scanf("%lld",&B[i]);
    }
    func(N, T, std::move(A), std::move(B));
    return 0;
}
