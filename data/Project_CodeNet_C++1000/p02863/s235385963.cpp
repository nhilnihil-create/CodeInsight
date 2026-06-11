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
#include<bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(ll i = 1;i <=  n; i++)
#define rreq(i,n) for(ll i = n;i >= 1;i--)
#define ALL(obj) begin(obj), end(obj)
#define RALL(a) rbegin(a),rend(a)
typedef long long int ll;
typedef long double ld;
const ll INF = 1e18;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
const int MOD = 1000000007;
int main(void) {
    int n, t; cin >> n >> t;
    vector<int> a(n + 10), b(n + 10);
    req(i, n) cin >> a[i] >> b[i];
    vector<vector<int>> dp1(n+10, vector<int>(t)), dp2(n+10, vector<int>(t));
    req(i, n) {
        rep(j, t) {
            dp1[i][j] = dp1[i - 1][j];
            if (j >= a[i]) dp1[i][j] = max(dp1[i][j], dp1[i - 1][j - a[i]] + b[i]);
        }
    }rreq(i, n) {
        rep(j, t) {
            dp2[i][j] = dp2[i + 1][j];
            if (j >= a[i])dp2[i][j] = max(dp2[i][j], dp2[i + 1][j - a[i]] + b[i]);
        }
    }
    int ans = 0;
    req(i, n) {
        rep(j, t) {
            ans = max(ans, dp1[i - 1][j] + dp2[i + 1][t - 1 - j] + b[i]);
        }
    }cout << ans << endl;
}