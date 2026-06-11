#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <istream>
#include <iterator>
#include <sstream>
#include <list>
#include <map>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <iomanip>
using namespace std;

#define BR "\n"
#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define ALL(cont) begin(cont),end(cont)
#define AS_MOD(a, b) ((((a) % (b) ) + (b)) % (b))
#define FEACH(it, cont) for(auto (it) = begin(cont); it!=end(cont);++it)
#define FEACHR(it, cont) for(auto (it) = rbegin(cont); it!=rend(cont);++it)
#define pb push_back
#define pob pop_back
#define fi first
#define se second
#define getll() ([](){ll s;scanf("%lld", &s);return s;})()
#define getld() ([](){ld s;scanf("%Lf", &s);return s;})()
#define prl(P) printf("%lld", P)
#define prd(P) printf("%.10Lf", P)
#define pr(P) printf(P)
#define MAX(V, T) V=max(V,T)
#define MIN(V, T) V=min(V,T)

#define DumpArray(cont, from, to) for(int __i=from;__i<to;++__i) {cout<<"(" <<__i<<": " << cont[__i]<<")";} cout<<endl;

/*
 * ***_bound(6)
 * 5 6 6 6 6 6 7 7 7
 *   ^lower    ^upper
 * void reverse(c.begin(), c.end())
 *
 * graph
 * seg tree
 * dp
 * brute force
 */
struct Comparator{
    int operator()(int l, int r) const {
        return r<l;
    }
};
//set<int, Comparator> S;

struct Vec{
    double v[2];
    string to_s(){
        return "("+to_string(v[0])+","+to_string(v[1])+")";
    }
    double& operator[](int t){
        return v[t];
    }
    Vec operator+(Vec t) {
        return {v[0]+t[0],v[1]+t[1]};
    }
    Vec& operator+=(Vec t) {
        v[0]+=t[0];v[1]+=t[1];
        return *this;
    }
    Vec operator-(Vec t) {
        return {v[0]-t[0],v[1]-t[1]};
    }
    Vec& operator-=(Vec t) {
        v[0]-=t[0];v[1]-=t[1];
        return *this;
    }
    Vec operator*(double t) {
        return {v[0]*t,v[1]*t};
    }
    Vec& operator*=(double t) {
        v[0]*=t;v[1]*=t;
        return *this;
    }
    double operator*(Vec t) {
        return v[0]*t[0]+v[1]*t[1];
    }
    Vec operator-(){
        return {-v[0],-v[1]};
    }
    static Vec Z;
};
Vec Vec::Z={0,0};

typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef vector<P> VP;
typedef pair<ll,ll> RP;

ll N,K;
vector<ll> H;
ll dpTable[310][310][310];
ll INF=(1000*1000*1000ll)*(1000*1000ll);
int main() {
    cin >> N >> K;
    H.resize(N);
    REP(i,N)
        cin>>H[i];
    H.pb(0);
    REP(i,310)
        REP(j,310)
            REP(k,310)
                dpTable[i][j][k]=INF;
    if (K>0) {
        for(int j=0;j<=N;++j) {
            MIN(dpTable[0][K-1][j],H[j]);
        }
    }
    dpTable[0][K][0]=H[0];
    for(int i=0;i<=N;++i) {
        for(int j=0;j<=K;++j) {
            for(int k=0;k<=N;++k) {
                if (j>0) {
                    MIN(dpTable[i+1][j-1][k],dpTable[i][j][k]);
                }
                MIN(dpTable[i+1][j][i+1],dpTable[i][j][k]+(H[i+1]>H[k]?H[i+1]-H[k]:0));
            }
        }
    }
    ll ans=INF;
    REP(i,N)
        REP(j,N+1)
            ans=min(ans,dpTable[N][i][j]);
    cout<<ans<<endl;
    return 0;
}
