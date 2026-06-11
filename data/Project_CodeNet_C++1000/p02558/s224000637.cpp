#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;

#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define rrep(i,x,y) for(ll i=(ll)(y)-1;i>=(x);i--)
#define all(x) (x).begin(),(x).end()
#define itrout(x) for(int i=0;i<x.size();i++) {cout << x[i] << (i==x.size()-1 ? "\n" : " ");}
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl
#define debugbit(x, n) cerr << #x << " = " << bitset<n>(x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl
#define itrdebug(x) cerr << #x << " "; for (auto & el : (x)) {cerr << (el) << " ";} cerr << endl
#define dassert(...) assert(__VA_ARGS__)
#else
#define debug(x)
#define debugbit(x, n)
#define itrdebug(x)
#define dassert(...)
#endif
//#define int long long

typedef long long ll;
const ll MOD = 1e9 + 7;
const long double EPS = 1e-8;

void solve(long long N, long long Q, std::vector<long long> t, std::vector<long long> u, std::vector<long long> v){
    atcoder::dsu d(N);
    rep(i,0,Q) {
        if (t[i] == 0) {
            d.merge(u[i], v[i]);
        } else {
            cout << (d.same(u[i], v[i]) ? 1 : 0) << endl;
        }
    }
}

signed main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    long long N;
    scanf("%lld",&N);
    long long Q;
    scanf("%lld",&Q);
    std::vector<long long> t(Q);
    std::vector<long long> u(Q);
    std::vector<long long> v(Q);
    for(int i = 0 ; i < Q ; i++){
        scanf("%lld",&t[i]);
        scanf("%lld",&u[i]);
        scanf("%lld",&v[i]);
    }
    solve(N, Q, std::move(t), std::move(u), std::move(v));
    return 0;
}
