#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = (n-1); i >= 0; --i)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 200005;
const int INF = 1001001001;
const int MOD = 1000000007;

struct Combination{
    vector<long long> fac, finv, inv;
    Combination(int n=1001001):fac(n+1), finv(n+1), inv(n+1) {
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i <= n; i++){
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    }
    long long operator()(int n, int k) const {
        if (n < k || n < 0 || k < 0) return 0;
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    }
};

int main(){
    int N, K;
    cin >> N >> K;

    Combination c;
    int m = N - K;

    for (int i = 1; i <= K; ++i) {
        ll a = c(K-1, i-1), b = c(m+1, i);
        ll ans = a * b % MOD;
        cout << ans << endl;
    }
}