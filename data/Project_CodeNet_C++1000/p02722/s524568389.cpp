#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<ll, ll>;
#define FOR(i, a, n) for(ll i=(ll)a; i<(ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
template<typename T> void chmin(T &a, const T &b) { a = min(a, b); }
template<typename T> void chmax(T &a, const T &b) { a = max(a, b); }
struct FastIO {FastIO() { cin.tie(0); ios::sync_with_stdio(0); }}fastiofastio;
#ifdef DEBUG
#include "../program_contest_library/memo/dump.hpp"
#else
#define dump(...)
#endif
constexpr ll INF = 1LL<<60;

int main() {
    ll n;
    cin >> n;    

    ll ret = 0;
    for(ll i=1; i*i<=n; ++i) {
        if(n%i==0) {
            if(i!=1) {
                ll t=n, div = i;
                while(t%div==0) t /= div;
                t %= div;
                if(t==1) ret++;
            }
            if(i!=n/i && n/i!=1) {
                ll t=n, div = n/i;
                while(t%div==0) t /= div;
                t %= div;
                if(t==1) ret++;
            }
        }
    }
    for(ll i=1; i*i<=n-1; ++i) {
        if((n-1)%i==0) {
            if(i!=1 && n%i!=0) {
                ret++;
            }
            if(i!=(n-1)/i && n%((n-1)/i)!=0) {
                ret++;
            }
        }
    }
    cout << ret << endl;

    return 0;
}
