// skip until line 65
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
#define MO(a) AS_MOD(a,mod)
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
struct Vec;
//set<int, Comparator> S;

// solution below
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
ll N,K;
ll mod=1000*1000*1000+7ll;
ll h[100000*2];
ll pow(ll X) {
    ll t=X;
    ll ret=1;
    for(int i=0;(N>>i)>0;++i) {
        if ((N>>i)&1) ret*=t;
        t*=t;
        ret=MO(ret);
        t=MO(t);
    }
    return ret;
}
vector<ll> num(100000+10,0);
void factoring_add(ll i,ll v) {
    for(int j=1;j*j<=i;++j) {
        if (i%j==0) {
            num[i/j]+=v;
            num[i/j]=MO(num[i/j]);
            if (j*j!=i) {
                num[j] += v;
                num[j] = MO(num[j]);
            }
        }
    }
}
int main() {
    cout.precision(10);
    cout << fixed;
    cin >> N >>K;
    ll ans=0;
    for(ll i=K;i>=1;--i) {
        num[i]=MO(pow(K/i)-num[i]);
        ans+=MO(num[i]*i);
        ans=MO(ans);
        factoring_add(i,num[i]);
    }
    cout << ans<<endl;

}
