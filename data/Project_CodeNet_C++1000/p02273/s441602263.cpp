#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
using Pd = pair<double,double>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
int n;
vector<Pd> ans;

void koch(Pd s,Pd t,int level){
    if(level==0){
        ans.push_back(s);
        return;
    }

    Pd c1 = {(2*s.first + t.first)/3.0,(2*s.second + t.second)/3.0};
    Pd c3 = {(s.first + 2*t.first)/3.0,(s.second + 2*t.second)/3.0};
    double dx = (t.first - s.first)/2.0;
    double dy = (t.second - s.second)/2.0;
    Pd c2 = {s.first + dx - (dy/sqrt(3)),s.second + dy + (dx/sqrt(3))};

    koch(s,c1,level-1);
    koch(c1,c2,level-1);
    koch(c2,c3,level-1);
    koch(c3,t,level-1);

    return ;
}

int main(){
    cin >> n;
    Pd s = {0,0};
    Pd t = {100,0};
    koch(s,t,n);
    ans.push_back(t);
    rep(i,ans.size()){
        printf("%f %f\n",ans[i].first ,ans[i].second);
    }
    return 0;
}
