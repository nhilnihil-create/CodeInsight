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
template <typename T> inline void voutput(T &v){
    rep(i, v.size()){
        if (i) cout << " " << v[i];
        else cout << v[i];
    }
    cout << endl;
}

ll pow_mod(ll a, ll b, ll m = mod){
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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // source code
    ll N, K;
    cin >> N >> K;
    ll ans = 0;
    vector<ll> A(K + 1);
    for(ll d = K; d >= 1; d--) {
        ll cnt = pow_mod((K / d), N);
        for(ll e = 2; e * d <= K; e++) {
            cnt -= A[e * d];
            cnt += mod;
            cnt %= mod;
        }
        A[d] = cnt;
        ans += A[d] * d;
        ans %= mod;
    }
    
    output(ans);
    
    return 0;
}
