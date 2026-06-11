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

template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

lli dp[6000][6000];

void func(long long N, std::string S){

    lli ans = 0;
    for(lli i=N;i>0;i--){
        for(lli j=N;j>i;j--){
            if(S[i-1] == S[j-1])chmax(dp[i-1][j-1],dp[i][j]+1);
            chmax(ans,min(dp[i-1][j-1],j-i));
        }
    }

    cout<<ans<<endl;

}

int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    std::string S;
    std::cin >> S;
    func(N, S);
    return 0;
}
