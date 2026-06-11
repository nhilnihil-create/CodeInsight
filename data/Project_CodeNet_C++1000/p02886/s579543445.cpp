#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;
using ll=long long;
using pint=pair<int,int>;
#define rep(i,a,b) for(ll i=a;i<ll(b);i++)
#define repr(i,a,b) for(ll i=a;i>=ll(b);i--)
#define el '\n'
#define ALL(x) x.begin(),x.end()
#define ALLR(x) x.rbegin(),x.rend()
#define ceil_div(a,b) ((a+(b-1))/b)
#define INF 1e9
#define DEBUG(x) cout<<"debug: "<<x<<endl
#define $in(v,n) ;rep(II,0,n)cin>>v[II]
inline void IN(void){return;}
template<typename F,typename... R>inline void IN(F& f, R&... r){cin>>f;IN(r...);}
template<class T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}


int main(){
    int n; IN(n);
    vector<int> d(n)$in(d, n);
    int ans = 0;
    rep(j, 1, n) rep(i, 0, j){
        ans += d[i] * d[j];
    }
    cout << ans << el;
    return 0;
}
