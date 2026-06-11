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

map<lli,lli> dd;

int main(){

    string s;
    cin>>s;

    dd[0]=1;
    lli now = 0;
    lli ten = 1;

    reverse(s.begin(),s.end());
    REP(i,0,s.size()){
        
        now %= 2019;
        ten %= 2019;
        now += (s.at(i)-'0')*ten;
        ten *= 10;
        ten %= 2019;
        now %= 2019;
        LOG(now);
        dd[now]++;
    }
    
    lli ans = 0;
    for(auto e:dd){
        ans += (e.second*(e.second-1))/2;
    }

    cout<<ans<<endl;

    return 0;
}
