#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<cassert>
#include<numeric>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
using namespace std;
const int INF = 1001001001;
const long long LINF = 1001002003004005006ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int,int> P;

int main(){
    int h,w,m;
    cin >> h >> w >> m;
    int x[m],y[m];
    rep(i,m)cin >> x[i] >> y[i];

    set<P> s;
    rep(i,m)s.insert(P(x[i],y[i]));
    map<int,int> mpx;
    map<int,int> mpy;
    rep(i,m)mpx[x[i]]++;
    rep(i,m)mpy[y[i]]++;
    int mx=0,my=0;
    for(auto p:mpx)chmax(mx,p.second);
    for(auto p:mpy)chmax(my,p.second);
    vector<int> xc;
    vector<int> yc;
    for(auto p:mpx)if(p.second==mx)xc.push_back(p.first);
    for(auto p:mpy)if(p.second==my)yc.push_back(p.first);

    for(auto i:xc){
        for(auto j:yc){
            if(s.find(P(i,j))==s.end()){
                cout << mx+my << endl;
                return 0;
            }
        }
    }
    cout << mx+my-1 << endl;
    return 0;
}