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
ll k, m, t, q;int  sum = 0, ans = 0; int n; string s;
const ld PI = acos(-1);
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
int main() {
    cin >> n >> m; vector<vector<char>> c(n, vector<char>(m));
    int L[2010][2010], R[2010][2001], D[2001][2010], U[2001][2010];
    rep(i, n) {
        rep(j, m) cin >> c[i][j];
    }
    rep(i, n) {
        if (c[i][0] == '.') L[i][0] = 1;
        else L[i][0] = 0;
        req(j, m - 1) {
            if (c[i][j] == '.') L[i][j] = L[i][j - 1] + 1;
            else L[i][j] = 0;
        }
    }
    rep(i, n) {
        if (c[i][m - 1] == '.')R[i][m - 1] = 1;
        else R[i][m - 1] = 0;
        rrep(j, m - 1) {
            if (c[i][j] == '.') R[i][j] = R[i][j + 1] + 1;
            else R[i][j] = 0;
        }
    }
    rep(j, m) {
        if (c[0][j] == '.') D[0][j] = 1;
        else D[0][j] = 0;
        req(i, n - 1) {
            if (c[i][j] == '.') D[i][j] = D[i - 1][j] + 1;
            else D[i][j] = 0;
        }
    }
    rep(j, m) {
        if (c[n-1][j] == '.') U[n-1][j] = 1;
        else U[n-1][j] = 0;
        rrep(i, n - 1) {
            if (c[i][j] == '.')U[i][j] = U[i + 1][j] + 1;
            else U[i][j] = 0;
        }
    }
    rep(i, n) {
        rep(j, m) {
            sum = max(L[i][j] + R[i][j] + U[i][j] + D[i][j] -3, sum);
        }
    }cout << sum << endl;
}
