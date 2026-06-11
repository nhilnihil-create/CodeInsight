#include <bits/stdc++.h>
using namespace std;
// types
typedef long long ll; 
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;
// IO
#define fo(i, n) for (int i = 0; i < n; i++)
#define fo1(i, n) for (int i = 1; i <= n; i++)
#define sc(n) scanf("%d", &n) 
#define sca(a, n) fo(i, n) sc(a[i])
#define pd(a) printf("%d ", a)
#define pld(a) printf("%d\n", a)
#define pda(a, n) fo(i, n) pd(a[i])
#define pl printf("\n")
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b) 
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
// math
const ll mod = 1e9+7;
template<typename T> T gcf(T a, T b) {return (b == 0) ? a : gcf(b, a%b);} 
template<typename T> T lcm(T a, T b) {return (a*b)/gcf(a, b);}
template<typename T> T sumTo(T x) {return x * (x+1) / 2;}
template<typename T> T sumSquaresTo(T x) {return x * (x+1) * (2*x+1) / 6;}
template<typename T> T ceildivMod(T n, T d) {return (n+d-1)/d;}

ll times(ll a, ll b) {
    return (a*b) % mod;
}

ll expB(ll b, ll e) {
    ll ans = 1;
    while (e) {
        if (e % 2) ans = times(ans, b);
        b = times(b, b);
        e >>= 1;
    }
    return ans;
}

ll inv(ll a) {
    return expB(a, mod-2);
}

ll divMod(ll a, ll b) {
    return times(a, inv(b));
}

ll comb(ll n, ll k) {
    ll ans = 1;
    for (ll i = n; i > n-k; i--) {
        ans = times(ans, i);
    }
    for (ll i = k; i > 0; i--) {
        ans = divMod(ans, i);
    }
    return ans;
}

ll f(ll x, ll y) {
    if ((x+y)%3) return 0;
    if (x > 2*y || y > 2*x) return 0;
    ll n = (x+y)/3;
    ll k = min(x, y)-n;
    return comb(n, k);
}

void solve() {
    ll x, y; cin >> x >> y;
    cout << f(x, y);
}

int main() {
    int t = 1;
    //scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}