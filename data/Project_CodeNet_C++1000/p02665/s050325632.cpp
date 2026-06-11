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
#define rep(i, n) for (ll i = 0; i < (int)(n); i++)
#define req(i,n) for(ll i = 1;i <=  n; i++)
#define rrep(i,n) for(ll i = n -1;i >= 0;i--)
#define ALL(obj) begin(obj), end(obj)
typedef long long int ll;
typedef long double ld;
const ll INF = (1LL << 62);
ll n,k, m, t,q,h1,h2,m1,m2; string s;
const ld PI = acos(-1);
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
int main() {
    cin >> n; vector<ll> a(n + 1), b(n + 1);
    rep(i, n+1) cin >> a[i];
    if (n == 0 && a[0] != 1) {
        cout << -1 << endl;
        return 0;
    }if (n != 0 && a[0] != 0) {
        cout << -1 << endl;
        return 0;
    }b[0] = 1;
    req(i, n) {
        if ((b[i - 1] - a[i - 1]) * 2 < a[i]) {
            cout << -1 << endl;
            return 0;
        }
        b[i] = min((b[i - 1] - a[i - 1]) * 2,INF);
    }ll now = a[n], res = a[n];
    rrep(i, n) {
        now = min(now + a[i], b[i]);
        res += now;
    }cout << res << endl;
}