#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<queue>
#include<deque>
#include<iomanip>
#include<sstream>
#include<cmath>
#include<tuple>
#include<bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(ll i = 1;i <=  n; i++)
#define rrep(i,n) for(ll i = n -1;i >= 0;i--)
#define ALL(obj) begin(obj), end(obj)
#define RALL(a) rbegin(a),rend(a)
typedef long long int ll;
typedef long double ld;
const ll INF = 1e18;
const double eps = 1e-8;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}int n, m, Q, b = 0, c = 0,dd = 0, sx,sy,gx,gy; string s;
const int MOD = 1e9 + 7;
int main(void) {
    cin >> n; vector<ll> a(n);
    ll ma = 0;
    rep(i, n) {
        cin >> a[i];
        ma = max(ma, a[i]);
    }ll ans = 0;
    dd = floor(log2(ma - 1))+1;
    rep(i, dd) {
        ll x = 1,y=0;
        rep(j, i) {
            x *= 2; x %= MOD;
        }
        rep(j, n) if (a[j] >> i & 1) ++y;
        ans += (y * (n - y) % MOD) * x % MOD;
        ans %= MOD;
    }cout << ans << endl;
}