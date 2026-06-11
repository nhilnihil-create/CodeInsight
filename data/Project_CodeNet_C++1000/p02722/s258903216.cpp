#pragma GCC optimize("fast-math")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC diagnostic ignored "-Woverflow"
 
#include <bits/stdc++.h>

using namespace std;

#define to_s to_string
#define MP make_pair
#define fi first
#define se second
#define pb push_back
// #define all(x) x.begin(), x.end()
#define gen_clock(x) ll x = clock(); cout << "Clock " << #x << " created" << endl;
#define check_clock(x) cout << "Time spent in " << #x << ": " << clock() - x << endl; x = clock();
#define reset_clock(x) x = clock(); cout << "Clock " << #x << " reseted" << endl;
 
//__builtin_popcount(x) - int
//__builtin_popcountll(x) - long long

typedef short sh;
typedef double db;
typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<sh, sh> pshsh;
typedef pair<bool, int> pbi;
typedef pair<char, int> pci;
typedef pair<char, char> pchch;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<ld> vld;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<sh> vsh;
typedef vector<pii> vpii;
typedef vector<pbi> vpbi;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<pci> vpci;
typedef vector<vsh> vvsh;
typedef vector<pld> vpld;
typedef vector<bool> vbool;
typedef vector<char> vchar;
typedef vector<vpii> vvpii;
typedef vector<vchar> vvchar;
typedef vector<vbool> vvbool;
typedef vector<string> vstring;

const short INF16 = ~(1 << 15);
const int INF32 = 2e9+11;
const int SZ = 4e5+11;
const int SZ2 = int(1e6+11);
const int mod = 1e9+7;
const int mod2 = 998244353;
const int PIVO = 4e5+11; 
const long long INF64 = 8e18;
const long long P1 = 53;
const long long P2 = 47;
const long double eps = 1e-10;
const long double PI = acosl(-1);

inline long long MOD(long long x){x %= mod, x += mod; return x % mod;}
inline long long MOD(long long x, long long m){x %= m, x += m; return x % m;}
inline long long T(int x){return 1ll * x * (x+1) >> 1;}
inline long long TT(int x){return 1ll * x * (x+1) * (x+2) / 6;}
inline long long gcd(long long a, long long b){return b ? gcd(b, a % b) : a;}
inline long long lcm(long long a, long long b){return a * b / gcd(a, b);}

long long fpow(long long a, long long b, long long mod){
    if(!b) return 1;
    if(b == 1) return a % mod;
    if(b & 1) return fpow(a, b ^ 1, mod) * a % mod;
    ll d = fpow(a, b >> 1, mod); return d * d % mod;
}

long long fpow(long long a, long long b){
    if(!b) return 1;
    if(b == 1) return a;
    if(b & 1) return fpow(a, b ^ 1) * a;
    ll d = fpow(a, b >> 1); return d * d;
}

vector<long long> f(long long n){
    vector<long long> res;

    for(int i = 2; 1ll * i * i <= n; i++)
        if(n % i == 0){
            res.push_back(i);
            if(i != n / i) res.push_back(n / i);
        }

    return res;
}

signed Solve(int num_test){
    long long n; cin >> n;

    int ans = 1 + (n != 2);

    for(long long k : f(n)){
        long long m = n;

        while(m % k == 0)
            m /= k;

        ans += (m % k == 1);
    }

    for(long long k : f(n-1)){
        long long m = n;

        while(m % k == 0)
            m /= k;

        ans += (m % k == 1);
    }

    cout << ans << endl;

    return 0;
}

signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed << setprecision(10);
    srand(time(NULL));
 
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
 
    // freopen("paths.in", "r", stdin);
    // freopen("paths.out", "w", stdout);
   
    int test = 1;
    // cin >> test;

    for(int i = 1; i <= test; i++)
        Solve(i);
}