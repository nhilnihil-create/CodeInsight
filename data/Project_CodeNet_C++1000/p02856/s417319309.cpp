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
#define LOG(x) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" ";
#define LOGE if(DEBUG)cout<<endl;

template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }



void func(long long M, std::vector<long long> d, std::vector<long long> c){

    lli ans = 0;

    lli sum = 0;
    REP(i,0,M){
        ans += c[i];
        sum += c[i]*d[i];
    }

    cout<<(ans-1)+(sum-1)/9<<endl;

}

int main(){
    // cout << fixed << setprecision(5);

    long long M;
    scanf("%lld",&M);
    std::vector<long long> d(M);
    std::vector<long long> c(M);
    for(int i = 0 ; i < M ; i++){
        scanf("%lld",&d[i]);
        scanf("%lld",&c[i]);
    }
    func(M, std::move(d), std::move(c));
    return 0;
}
