#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<deque>
#include<array>
#include<map>

#define REP(i,a,b) for(int i = (a); i < b; ++i)
#define inf 1e9+10
#define MOD 1000000007

using ll = long long;
using ull = unsigned long long;
using namespace std;

inline ll modpow(ll x, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

inline ll mod(ll val, ll m) {
    ll res = val % m;
    if (res < 0) res += m;
    return res;
}

template <typename T>
struct PrimeFact {
    vector<T> spf;
    PrimeFact(T N) { init(N); }
    void init(T N) { // 前処理。spf を求める
        spf.assign(N + 1, 0);
        for (T i = 0; i <= N; i++) spf[i] = i;
        for (T i = 2; i * i <= N; i++) {
            if (spf[i] == i) {
                for (T j = i * i; j <= N; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
    }
    map<T, T> get(T n) { // nの素因数分解を求める
        map<T, T> m;
        while (n != 1) {
            m[spf[n]]++;
            n /= spf[n];
        }
        return m;
    }
};

int main() {
    int n;
    cin >> n;
    int sum = 0;
    REP(i, 1, n + 1) {
        sum += (n - 1) / i;
    }
    
    cout << sum;

    return 0;
}