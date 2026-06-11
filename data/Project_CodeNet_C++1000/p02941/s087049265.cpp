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

void func(long long N, std::vector<long long> A, std::vector<long long> B){

    priority_queue<pair<lli,lli>> q;

    REP(i,0,N){
        if(B[i]<A[i]){
            cout<<-1<<endl;
            return;
        }
        if(B[i] != A[i])q.push({B[i],i});
    }

    lli cnt = 0;
    while(q.size()){
        pair<lli,lli> top = q.top();
        q.pop();
        lli i = top.second;
        lli diff = B[(i+1)%N] + B[(i+N-1)%N];
        lli able = (B[i]-A[i])/(diff);
        if(able == 0){
            cout<<-1<<endl;
            return;
        }
        B[i] -= (able * diff);
        cnt += able;
        if(B[i] != A[i])q.push({B[i],i});
    }

    cout<<cnt<<endl;

}

int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    std::vector<long long> A(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&A[i]);
    }
    std::vector<long long> B(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&B[i]);
    }
    func(N, std::move(A), std::move(B));
    return 0;
}
