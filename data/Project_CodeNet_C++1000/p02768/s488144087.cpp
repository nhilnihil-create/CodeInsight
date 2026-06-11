#include <bits/stdc++.h>
#define rep(i, z, n) for(int64_t i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
#define PI 3.14159265358979
//const int64_t INF = 1LL << 60;
const int INF = 1 << 29;
const int64_t MOD = 1000000007;
//const int64_t INF = 998244353;
using namespace std;
typedef pair<int64_t, int64_t> P;

int64_t powmod(int64_t x, int64_t n){
    //pow(x, n) % MOD
    int64_t ret = 1;
    while(n > 0){
        if(n & 1) ret = ret * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return ret;
}

int64_t nikou(int64_t A, int64_t B){
    int64_t x = 1, y = 1;
    rep(i, 0, A){
        x *= (B - i);
        y *= (i + 1);
        x %= MOD;
        y %= MOD;
    }
    y = powmod(y, MOD - 2);
    return x * y % MOD;
}

int main(){
    int64_t n, a, b;
    cin >> n >> a >> b;
    int64_t x = powmod(2, n) - 1;
    int64_t y = nikou(a, n);
    int64_t z = nikou(b, n);
    int64_t ans = x - y - z;
    cout << (ans % MOD + MOD) % MOD << endl;
}