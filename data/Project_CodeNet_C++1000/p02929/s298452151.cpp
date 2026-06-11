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

void invalid() {
    output(0);
    exit(0);
}

ll fact(ll n) {
    ll ans = 1;
    rep(i, 1, n + 1) (ans *= i) %= mod;
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    // source code
    ll N;
    string s;
    cin >> N >> s;
    
    ll ans = 1;
    int l = 1, r = 0;
    if(s[0] != 'B') invalid();
    int cur = 0;
    rep(i, 1, 2 * N) {
        if(s[i] == s[i - 1]) {
            cur ^= 1;
        }
        if(cur == 1) {
            ans *= (l - r);
            ans %= mod;
        }
        if(cur == 0) l++;
        else r++;
        if(l < r) invalid();
    }
    if(l != r) invalid();
    ans *= fact(N);
    ans %= mod;
    output(ans);
    
    return 0;
}
