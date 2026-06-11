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

void func(string  &S){

    map<lli,lli> cnt;

    cnt[0]++;
    lli num = 0;
    lli ten = 1;
    reverse(S.begin(),S.end());
    REP(i,0,S.size()){
        num += (S[i]-'0')*ten;
        num%=2019;
        ten *= 10;
        ten %=2019;
        cnt[num]++;
    }

    lli ans = 0;
    for(auto e:cnt){
        ans += (e.second)*(e.second-1)/2;
    }

    cout<<ans<<endl;

}

int main(){
    // cout << fixed << setprecision(5);

    string s;
    cin>>s;
    func(s);
    return 0;
}
