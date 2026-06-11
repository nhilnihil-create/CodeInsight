#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;
typedef tuple<long long, long long, long long> tllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
bool compTuple(const tllint& arg1, const tllint& arg2) { return get<2>(arg1) > get<2>(arg2); }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

llint modpow(llint a, llint n) {
    if(n==0) return 1LL;
    if(n%2==1) return a*modpow(a, n-1)%MOD;

    llint t;
    t = modpow(a, n/2);
    return t*t%MOD;
}

int main(void) {
    llint n, k;
    cin >> n >> k;

    llint ans = 0, tmp;
    vector<llint> res(k);
    for(llint ik=k;ik>=1;ik--) {
        tmp = modpow(k/ik, n);
        llint jk = ik;
        while(1) {
            jk += ik;
            if(jk>k) break;
            tmp -= res[jk-1];
            if(tmp<0) tmp += MOD;
        }
        res[ik-1] = tmp;
        ans += ik * res[ik-1];
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}
