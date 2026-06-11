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

lli P[5100];
lli C[5100]; 

void func(int N, int K){

    lli ans = -INF;
    REP(i,0,N){
        lli now = P[i];
        lli sum = C[now];
        chmax(ans,sum);
        lli cnt = 1;
        while(now!=i){
            now = P[now];
            sum+=C[now];
            cnt++;
            if(cnt<=K)chmax(ans,sum);
        }
        if(cnt>K)continue;
        if(sum<=0)continue;

        lli temae = K/cnt - 2;
        if(temae < 0)temae = 0;
        lli nowSum = sum*temae;
        lli nowCnt = temae*cnt;
        chmax(ans,nowSum);

        while(nowCnt < K){
            now = P[now];
            nowSum+=C[now];
            nowCnt++;
            chmax(ans,nowSum);
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
        scanf("%lld",&P[i]);
        P[i]--;
    }
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&C[i]);
    }
    func(N, K);
    return 0;
}