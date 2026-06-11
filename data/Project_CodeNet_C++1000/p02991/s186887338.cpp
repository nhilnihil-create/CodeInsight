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

lli dp[3][100100];
vector<lli> G[100100];

void func(long long N, long long M, std::vector<long long> u, std::vector<long long> v, long long S, long long T){

    queue<pair<lli,lli>> q;
    q.push({S,0});

    while(q.size()){
        lli now = q.front().first;
        lli nowC = q.front().second;
        LOG2(now,nowC);
        q.pop();
        lli nextC = (nowC+1)%3;
        lli nextD = nowC+1;
        for(auto e:G[now]){
            if(dp[nextC][e]!=INF)continue;
            LOG2(e,nextC);
            dp[nextC][e] = nextD;
            q.push({e,nextD});
        }
    }
    if(dp[0][T]==INF)cout<<-1<<endl;
    else cout<<dp[0][T]/3<<endl;

}

int main(){
    // cout << fixed << setprecision(5);

    REP(i,0,3)REP(j,0,100100)dp[i][j]=INF;
    long long N;
    scanf("%lld",&N);
    long long M;
    scanf("%lld",&M);
    std::vector<long long> u(M);
    std::vector<long long> v(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&u[i]);
        scanf("%lld",&v[i]);
        u[i]--,v[i]--;
        G[u[i]].push_back(v[i]);
    }
    long long S;
    scanf("%lld",&S);
    long long T;
    scanf("%lld",&T);
    S--,T--;
    func(N, M, std::move(u), std::move(v), S, T);
    return 0;
}
