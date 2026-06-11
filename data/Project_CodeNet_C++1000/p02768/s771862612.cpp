#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<iomanip>
#include<sstream>
#include<cmath>
#include<bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(int i = 1;i <=  n; i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
typedef long long int ll;
typedef long double ld;
const ll INF = (1 << 31);
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
const int MAX = 510000;
const int MOD = 1000000007;
ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}
int main() {
	int n, a, b; cin >> n >> a >> b;
    ll ans = mod_pow(2, n, MOD) - 1;
    ll sum = 1,y=1; int j = 1;
    for (int i = n; i >= n-a+1; i--) {
        sum *= i; sum %= MOD;
        y *= j; j++; y %= MOD;
    }
    y = mod_pow(y, MOD - 2, MOD);
    ans =(ans - (sum * y) % MOD)%MOD;
    ans += MOD;
    sum = 1, y = 1; j = 1;
    for (int i = n; i >= n - b + 1; i--) {
        sum *= i; sum %= MOD;
        y *= j; j++; y %= MOD;
    }ans += MOD;
    y = mod_pow(y, MOD - 2, MOD);
    ans = (ans - (sum * y) % MOD) % MOD;
    cout << ans % MOD << endl;
}