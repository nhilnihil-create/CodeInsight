#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define ALL(V) V.begin(),V.end()
#define RALL(V) V.rbegin(),V.rend()
#define PI (3.141592653589794)
#define TO_STRING(VariableName) # VariableName
#define LOG(x) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<endl;
#define LOG2(x,y) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<endl;
#define LOG3(x,y,z) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<" "<<TO_STRING(z)<<"="<<z<<endl;
#define LOG4(w,x,y,z) if(DEBUG)cout<<TO_STRING(w)<<"="<<w<<" "<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<" "<<TO_STRING(z)<<"="<<z<<endl;

template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

void func(long long N, std::vector<long long> P){

    multiset<lli> large;
    large.insert(0);
    large.insert(0);
    large.insert(N+1);
    large.insert(N+1);

    map<lli,lli> toI;
    REP(i,0,N)toI[-P[i]] = i+1;

    lli ans = 0;
    for(auto e:toI){
        lli now = e.second;
        lli sum = 0;
        auto rig = large.lower_bound(now);
        auto rig2 = rig;
        rig2++;
        auto lef = large.lower_bound(now);
        lef--;
        auto lef2 = lef;
        lef2--;
        LOG4(ans,now,*lef,*rig);
        LOG4(*lef2,*lef,*rig,*rig2);
        sum += (*rig-now)*(*lef-*lef2);
        sum += (now-*lef)*(*rig2-*rig);
        sum *= (-e.first);

        large.insert(now);
        ans += sum;
    }

    cout<<ans<<endl;

}

int main(){
    // cout << fixed << setprecision(5);

    long long N;
    scanf("%lld",&N);
    std::vector<long long> P(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&P[i]);
    }
    func(N, std::move(P));
    return 0;
}
