#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define ALL(n) begin(n),end(n)
#define IN(a, x, b) (a<=x && x<b)
#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
template<class T> inline T CHMAX(T & a, const T b) { return a = (a < b) ? b : a; }
template<class T> inline T CHMIN(T & a, const T b) { return a = (a > b) ? b : a; }

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);

int main()
{
    INIT;
    int n, d;
    cin >> n >> d;
    float ans_infloat = n / ( d * 2.0 + 1);
    int ans = ceil(ans_infloat);
    cout << ans << endl;
    return 0;
}