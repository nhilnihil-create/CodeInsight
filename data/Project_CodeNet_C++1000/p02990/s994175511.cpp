#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <sstream>
#include <string>
#define _repargs(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _repargs(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define mod 1000000007
#define inf 2000000007
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;
template <typename T>
inline void output(T a, int p = 0) {
    if(p) cout << fixed << setprecision(p)  << a << "\n";
    else cout << a << "\n";
}
// end of template

ll f[400000];

void calc() {
    f[0] = 1;
    rep(i, 1, 400001) {
        f[i] = f[i - 1] * i;
        f[i] %= mod;
    }
}

ll pow_mod(ll a, ll b, ll m){
    ll ret = 1;
    while (b > 0) {
        if (b & 1) {
            ret = ret * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return ret;
}

ll inv_mod(ll a, ll m){
    return pow_mod(a, m - 2, m);
}

ll comb(ll n, ll r) {
    ll ret = f[n];
    ret *= inv_mod(f[r], mod);
    ret %= mod;
    ret *= inv_mod(f[n - r], mod);
    ret %= mod;
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // source code
    ll N, B;
    cin >> N >> B;
    ll R = N - B;
    calc();
    for(ll k = 1; k <= B; k++) {
        if(R + 1 < k) {
            output(0);
            continue;
        }
        ll c = comb(B - 1, k - 1);
        ll d = comb(R + 1, k);
//        cout << k<< "," <<R + 1 << endl;
        output(c * d % mod);
    }
    
    return 0;
}
