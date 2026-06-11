#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<iomanip>
#include<sstream>
#include<cmath>
#include<bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(int i = 1;i <=  n; i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(obj) begin(obj), end(obj)
typedef long long int ll;
typedef long double ld;
const ll INF = (1LL << 60);
const int INf = 1e9;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T& val) {
    fill((T*)array, (T*)(array + N), val);
}
const ll MOD = 1000000007; int ans =0;
int main() {
    int n, m,p; cin >> n >> m;
    vector<ll> a(m), b(m),bit(m);
    rep(i, m) {
        cin >> a[i] >> b[i];
        int ma = 0;
        rep(j, b[i]) {
            cin >> p; p--;
            ma += pow(2, p);
        }
        bit[i] = ma;
    }ll dp[1 << 12];
    Fill(dp, INF);
    dp[0] = 0;
    rep(i, (1 << n)) {
        rep(j, m) {
            dp[i | bit[j]] = min(dp[i | bit[j]], dp[i] + a[j]);
        }
    }
    if (dp[(1 << n) - 1] == INF) cout << -1 << endl;
    else cout << dp[(1 << n) - 1 ] << endl;
}