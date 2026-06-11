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

void func(std::string s, std::string t){

    vector<lli> pos[26];
    REP(i,0,s.size()){
        pos[s[i]-'a'].push_back(i);
    }

    lli now=0;
    REP(i,0,t.size()){
        LOG3(i,t[i],now);
        lli al = t[i]-'a';
        if(pos[al].size()==0){
            cout<<-1<<endl;
            return;
        }
        auto itr = lower_bound(pos[al].begin(),pos[al].end(),now%s.size());
        if(itr == pos[al].end()){
            now = (now/s.size() + 1)*s.size();
            itr = lower_bound(pos[al].begin(),pos[al].end(),now%s.size());
        }
        now = now/s.size()*s.size() + (*itr) + 1;
    }

    cout<<now<<endl;

}

int main(){
    // cout << fixed << setprecision(5);

    std::string s;
    std::cin >> s;
    std::string t;
    std::cin >> t;
    func(s, t);
    return 0;
}
