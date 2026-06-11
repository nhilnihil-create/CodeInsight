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
#define rep(i, n) for (long long int i = 0; i < (int)(n); i++)
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
ll MD(ll a) {
    ll temp = a % MOD;
    if (temp < 0) temp += MOD;
    return temp;
}
int main() {
    int n, k; cin >> n >> k; ll sum = 0, t,p;
    int xx[100010]; Fill(xx, 0);
    for (int i = k; i > 0; i--) {
        int x = k / i;
        t = mod_pow(x, n, MOD);
        int j = 2;
        while (j*i <= k) {
            t = MD(t - xx[j * i] % MOD);
            j++;
        }
        xx[i] = t;
    }
    rep(i, k + 1) sum = (sum + xx[i] * i % MOD) % MOD;
    cout << sum << endl;
}