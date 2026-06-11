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
#define ceil_div(a,b) (a+(b-1))/b
#define INF 1e9
#define DEBUG(x) cout<<"debug: "<<x<<endl
#define $in(v,n) ;rep(II,0,n)cin>>v[II]
inline void IN(void){return;}
template<typename F,typename... R>inline void IN(F& f, R&... r){cin>>f;IN(r...);}
template<class T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

#include <iomanip>

int main(){
    int n; IN(n);
    vector<pint> d(n);
    rep(i, 0, n) IN(d[i].first, d[i].second);

    vector<int> c(n); rep(i, 0, n) c[i] = i;
    double sum = 0;
    do{
        double dist = 0;
        rep(i, 1, n){
            int a = c[i-1], b = c[i];
            double x = pow(d[a].first - d[b].first, 2);
            double y = pow(d[a].second - d[b].second, 2);
            dist += sqrt(x+y);
        }
        sum += dist;
    }while(next_permutation(ALL(c)));

    ll q = 1; rep(i, 1, n+1) q *= i;
    cout << fixed << setprecision(15) << sum/q << el;
    return 0;
}
