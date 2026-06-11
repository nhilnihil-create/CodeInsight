#include <bits/stdc++.h>
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

void solve(long long k, long long q, std::vector<long long> d, std::vector<long long> n, std::vector<long long> x, std::vector<long long> m){
    rep(qi,0,q) {
        ll answer = n[qi] - 1;
        debug(answer);
        vector<ll> di(k);
        rep(i,0,k) di[i] = d[i] % m[qi];
        ll dsum = accumulate(all(di), 0LL);
        rep(i,0,k) {
            if (di[i] == 0) {
                debug(i);
                answer -= (n[qi]-1) / k;
                if (i < (n[qi] - 1) % k) answer--;
            }
        }
        ll ani = x[qi] + ((n[qi]-1) / k) * dsum;
        rep(i,0,(n[qi]-1) % k) {
            ani += di[i];
        }
        debug(answer);
        debug(ani);
        answer -= ani / m[qi] - x[qi] / m[qi];
        cout << answer << endl;
    }
}

signed main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    long long k;
    scanf("%lld",&k);
    long long q;
    scanf("%lld",&q);
    std::vector<long long> d(k-1-0+1);
    for(int i = 0 ; i < k-1-0+1 ; i++){
        scanf("%lld",&d[i]);
    }
    std::vector<long long> n(q);
    std::vector<long long> x(q);
    std::vector<long long> m(q);
    for(int i = 0 ; i < q ; i++){
        scanf("%lld",&n[i]);
        scanf("%lld",&x[i]);
        scanf("%lld",&m[i]);
    }
    solve(k, q, std::move(d), std::move(n), std::move(x), std::move(m));
    return 0;
}
