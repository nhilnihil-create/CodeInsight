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

bool win[100100];

void func(long long N, long long K, long long R, long long S, long long P, std::string T){

    map<char,lli>score;
    score['r']=P;
    score['s']=R;
    score['p']=S;

    lli ans = 0;
    REP(i,0,N){
        if(i<K){
            win[i]=true;
            ans+=score[T[i]];
        }
        else{
            if(T[i-K]==T[i] && win[i-K])continue;
            win[i]=true;
            ans += score[T[i]];
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
    long long R;
    scanf("%lld",&R);
    long long S;
    scanf("%lld",&S);
    long long P;
    scanf("%lld",&P);
    std::string T;
    std::cin >> T;
    func(N, K, R, S, P, T);
    return 0;
}
