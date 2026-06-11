#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define repn(i, n) for(int (i) = 1; (i) <= (n); (i)++)
#define repr(i, n) for(int (i) = (n-1); (i) >= 0; (i)--)
#define all(x) (x).begin(), (x).end()
#define lint long long
#define ulint unsigned long long
#define fi first
#define se second
#define setpre(x) cout << fixed << setprecision(x)
#define ii(x) int x; cin >> (x)
#define ii2(x, y) int x, y; cin >> (x) >> (y)
#define ii3(x, y, z) int x, y, z; cin >> (x) >> (y) >> (z)
#define out(x) cout << (x) << endl
#define outs(x) cout << (x) << " "
#define yn(x) cout << ((x)?("Yes"):("No")) << endl
#define YN(x) cout << ((x)?("YES"):("NO")) << endl
#define bit_c(x) __builtin_popcountll(x)

inline void logger(){ cout << endl; }
template<typename A, typename... B>
void logger(const A& a, const B&... b){
    cout << a << " , ";
    logger(b...);
}

typedef pair<lint, lint> P;
const lint MOD = 1000000007;
const lint MOD9 = 998244353;
const lint INF = MOD * MOD;
const int MAX = 200005;

/* ...o(^-^)o... */

long long fac[MAX], facinv[MAX], inv[MAX];
void facinit(){
    fac[0] = fac[1] = 1;
    facinv[0] = facinv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        facinv[i] = facinv[i - 1] * inv[i] % MOD;
    }   
}

int main(){
    facinit();

    int n; cin >> n; n *= 2;
    string s; cin >> s;
    vector<int> t(n); t[0] = 0;
    rep(i, n - 1){
        if(s[i] == s[i+1]) t[i+1] = t[i] ^ 1;
        else t[i+1] = t[i];
    }

    vector<int> v(n), w(n);
    v[0] = 1; w[0] = 0;
    rep(i, n - 1){
        v[i+1] = v[i]; w[i+1] = w[i];
        if(t[i+1] == 0) v[i+1]++;
        else w[i+1]++;
    }

    if(s[0] == 'W' || s[n-1] == 'W' || v[n-1] != w[n-1]){
        out(0); return 0;
    }

    lint ans = 1;
    rep(i, n){
        if(t[i] == 1){
            ans *= v[i] - w[i] + 1;
            ans %= MOD;
        }
    }
    ans *= fac[n/2]; ans %= MOD;
    out(ans);
}
