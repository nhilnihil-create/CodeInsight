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
const int mod = 1e9+7;
template<typename T> T gcf(T a, T b) {return (b == 0) ? a : gcf(b, a%b);} 
template<typename T> T lcm(T a, T b) {return (a*b)/gcf(a, b);}
template<typename T> T sumTo(T x) {return x * (x+1) / 2;}
template<typename T> T sumSquaresTo(T x) {return x * (x+1) * (2*x+1) / 6;}
template<typename T> T ceilDiv(T n, T d) {return (n+d-1)/d;}

vector<bool> binaryBackwards(ll n) {
    // returns binary representation of the vector backwards
    vector<bool> ans;
    while (n > 0) {
        ans.push_back(n%2);
        n /= 2;
    }
    return ans;
}

ll emod(ll base, ll exponent) {
    vector<bool> bb = binaryBackwards(exponent);
    ll ans = 1;
    ll bp = base % mod;
    for (int i = 0; i < bb.size(); i++) {
        if (bb[i]) {
            ans *= bp;
            ans %= mod;
        }
        bp = (bp * bp) % mod;
    }
    return ans;
}

ll comb(ll n, ll r) {
    ll ans = 1;
    for(ll x = n; x > n-r; x--) ans = (ans*x) % mod;
    ll rf = 1;
    for (ll i = 2; i <= r; i++) rf = (rf*i) % mod;
    return (ans * emod(rf, mod-2)) % mod;
}

void solve() {
    ll n, a, b; cin >> n >> a >> b;
    // formula = 2^n - 1 - nCa - nCb
    ll x = emod(2, n)-1;
    ll nCa = comb(n, a);
    ll nCb = comb(n, b);
    ll ans = (x-nCa-nCb) % mod;
    if (ans < 0) ans += mod;
    cout << ans;
} 

int main() {
    int t = 1;
    //scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}