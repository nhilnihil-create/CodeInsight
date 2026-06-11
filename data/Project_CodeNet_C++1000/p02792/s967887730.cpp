#include <bits/stdc++.h>
#define REP(i, n) for(long long i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define FORR(i, a, b) for(int i=(b)-1; i>=(a); --i)
#define ALL(v) v.begin(), v.end()
#define FS first
#define SC second
#define SZ(a) int((a).size())
#define SORT(c) sort((c).begin(),(c).end())
#define MEMSET(v, h) memset((v), h, sizeof(v))
#define SQR(x) ((x) * (x))
#define BIT(n) (1LL<<(n))
#define PCNT(x) __builtin_popcountll(x)
#define GCD(x,y) __gcd(x,y)
#define LCM(x,y) x/__gcd(x,y)*y
#define PB push_back
#define MP make_pair
#define endl "\n"
using namespace std;
typedef long long lint;
typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<bool> VB;
typedef vector<vector<int> > VVI;
typedef vector<vector<LL> > VVLL;
typedef vector<vector<bool> > VVB;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(10);

    long long N, ans = 0;
    cin >> N;
    long long c[10][10] = {{0}};
    FOR(i,1,N+1) {
        long long a = i;
        long long b = a % 10;
        while (a >= 10) a /= 10;
        c[a][b]++;
    }
    REP(i,10) REP(j,10) ans += c[i][j] * c[j][i];
    cout << ans << endl;
}

