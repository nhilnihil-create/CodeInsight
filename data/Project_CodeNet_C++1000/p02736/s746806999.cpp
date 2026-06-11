#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
 
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,tune=native")
 
using namespace __gnu_pbds;
using namespace std;
     
#define mp make_pair
#define sz(x) (int)((x).size())
#define all(x) (x).begin(),(x).end()
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define eb emplace_back
 
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;
typedef long long ll;
typedef unsigned long long ull;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< ll > vll;
typedef vector< vll > vvll;
typedef vector< pii > vpii;
typedef vector< vpii > vvpii;
typedef vector< pll > vpll;
typedef long double ld;
typedef vector< ld > vld;
 
const ll MOD2 = 1e9 + 7;
const int MOD = 1e9 + 7;
 
const ull infull = numeric_limits<unsigned long long>::max();
 
void fix(int &x, ll MOD) {
    x = (x % MOD);
    if(x < 0) x += MOD;
    return;
}
 
ll lgput(ll a, ll b, ll MOD) {
    ll ret = 1;
    a %= MOD;
    while(b) {
        if(b&1) ret = ret*a % MOD;
        a = a*a % MOD;
        b >>= 1;
    }
 
    return ret;
}
 
ll inv(ll a, ll MOD) {
    return lgput(a, MOD-2, MOD);
}
 
struct f {
    int a, b;
    f(int _a = 0, int _b = 0) : a(_a) ,b(_b) {}
    ll eval(int x) {
        return 1ll*x*a + b;
    }
};
 
int binarySearch(int x, vi &v) {
    int pos = 0;
    int l = 1, r = sz(v);
    while(l <= r) {
        int m = l + r >> 1;
        if(v[m] <= x) {
            pos = m;
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
 
    return pos;
}

int getParity(int n, int k){
    int put = 0;
    for(int i = 2; i <= n; i += i) {
        put += n / i;
        put -= k / i;
        put -= (n-k) / i;
    }

    return (put == 0);
}
int getAnsParity(vector< int > v) {
    int ret = 0;
    for(int i = 0; i < v.size(); ++i) {
        if(v[i] == 1 && getParity(v.size()-1, i)) ret ^= 1;
    }

    return ret;
}

int main() { 
    #ifdef BLAT
        freopen("stdin", "r", stdin);
        freopen("stderr", "w", stderr);
    #endif
 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.precision(12);
    srand(time(NULL));
        
    int n;
    string s;
    cin >> n >> s;

    vi v(n);
    for(int i = 0; i < n; ++i) {
        v[i] = s[i] - '1';
    }

    int t1 = getAnsParity(v);
    if(t1 == 1) {
        return puts("1"), 0;
    }

    if(count(all(v), 1)) {
        return puts("0"), 0;
    }

    for(auto &x : v) {
        x /= 2;
    }

    int t2 = getAnsParity(v);
    if(t2 == 1) {
        return puts("2"), 0;
    }

    puts("0"), 0;

    return 0;  
}