#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef unordered_set<int> si;
typedef pair<int, int> pp;

#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define all(e) (e).begin(), (e).end()
#define pb push_back


template <typename T>
void printV(vector<T> A) {
    if (A.empty()) cerr << "EMTPY\n";
    else { 
        cerr << "[";
        for (int i = 0; i < A.size() -1 ; ++i) {
            cerr << A[i] << ", ";
        }
        if (A.size()) cerr << A.back() << "]\n";
    }
}


template <typename T>
void printVV(vector<vector<T>> A) {
    cerr << "[";
    for (auto v : A) {
        printV<T>(v);
    }
    cerr << "]";
}

template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cerr << name << ": " << arg1 << endl;
}

template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&& ...args) {
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << ": " << arg1 << " |";
    __f(comma + 1, args...);
}

const int MAXN = 2002;
ll fact[MAXN], inv[MAXN], finv[MAXN];
const ll mod = 1e9 + 7;


ll calc(ll n, ll i, ll k) {
    ll r = n-k+1;
    if (r-i < 0) return 0;
    ll x =  (((fact[r] * finv[r-i]) % mod) * finv[i]) % mod;
    ll y = (((fact[k-1] * finv[k-1-(i-1)]) % mod) * finv[i-1]) % mod;
    return (x*y) % mod;
}

int main(int argc, char **argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, k; cin >> n >> k;
    fact[0] = fact[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        fact[i] = (i * fact[i-1]) % mod;
    }

    inv[0] = inv[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        inv[i] = (inv[mod%i] * (mod-mod/i)) % mod;
    }
    
    finv[0] = finv[1] = 1;
    for (int i = 2; i < MAXN; ++i) {
        finv[i] = (finv[i-1] * inv[i]) % mod;
    }

    for (ll i = 1; i <= k; ++i) {
        cout << calc(n,i,k) << endl;
    }

    return 0;
}

