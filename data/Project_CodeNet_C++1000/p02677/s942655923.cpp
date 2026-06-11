#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORR(i, a, b) for (int i = a; i <= b; i++)
#define REP(i, a, b) for (int i = b - 1; i >= a; i--)
#define FORI(i, a, b, inc) for (int i = a; i <= b; i += inc)
#define FORRI(i, a, b, inc) for (int i = a; i < b; i += inc)
#define REPD(i, a, b, dec) for (int i = b - 1; i >= a; i -= dec)
#define SORT(a, n) sort(a, a + n, greater<int>())
#define PREC(n) cout << fixed << setprecision(n)
#define ULL unsigned long long
#define FT first
#define SN second
#define Vsort(v) sort(v.begin(), v.end())
#define FORV(it, l) for (auto it : l)
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define RESET(a, b) memset(a, b, sizeof(a))
#define PI acos(-1)
#define S " "
#define VSE(v) v.begin(), v.end()
typedef vector<int> VC;
typedef vector<long long> VCL;
typedef vector<VC> VCC;
typedef pair<int, int> PR;
typedef vector<PR> VPR;
typedef long long LL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef set<PR> STP;

void solve()
{
    /*Md. Bokhtiar Nadeem Shawon
    Institute of Information Technology
    Jahangirnagar University
    */
    int a,b,h,m;
    cin >> a >> b >> h >> m;
    double d,ans;
    d =abs((((60 * h) + m) * 1.00000000000000000000) / 2.00000000000000000000) - (6 * m);
    if(d>180.00000000000000000000)
        d = 360.00000000000000000000 - d;
    d = (PI * d) / 180.00000000000000000000;
    ans = sqrt(a * a + b * b - (2 * a * b * cos(d)));
    PREC(20) << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    /*cin >> t;
    while (t--)*/
    solve();
    return 0;
}