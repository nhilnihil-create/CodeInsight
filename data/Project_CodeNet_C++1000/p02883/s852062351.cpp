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
}ll n, m, s, t, r, Q, b, c; 
vector<ll> a,f,D;
const int MOD = 1e9 + 7;
bool ch(ll x) {
    ll sum = 0;
    rep(i, n) {
        sum += max(a[i] - x / f[i],0LL);
    }return sum <= m;
}
int main(void) {
    cin >> n >> m; a.resize(n); f.resize(n); D.resize(n);
    rep(i, n)  cin >> a[i];
    rep(i, n) cin >> f[i];
    sort(ALL(a)); sort(RALL(f));
    ll left = -1, right = 1e18;
    while (right - left > 1) {
        ll mid = (left + right) / 2;
        if (ch(mid)) right = mid;
        else left = mid;
    }cout << right << endl;
}