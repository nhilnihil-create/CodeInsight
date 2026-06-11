#include <bits/stdc++.h>
#define REP(i,n) for (int i=0; i<(n); ++i)
#define REPR(i,n,m) for (int i=(n); i>=(m); --i)
using namespace std;
using LL = long long;
using LD = long double;
using PLL = pair<long long, long long>;
using PLD = pair<long double, long double>;
using VLL = vector<long long>;
using VLD = vector<long double>;
using VPLD = vector<PLD>;

const int INF = numeric_limits<int>::max();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k, n;
    cin >> n >> k;
    VLD p(n);
    REP(i,n) cin >> p[i];

    VLD e(n);
    REP(i,n) {
        if (i==0) e[i] = ((p[i]*(p[i]+1.0)) / 2.0) / p[i];
        else e[i] = ((p[i]*(p[i]+1.0)) / 2.0) / p[i] + e[i-1];
    }

    VLD s(n+1, 0.0);
    REP(i,n) s[i+1] = e[i];

    LD ans = 0.0;
    for (int i=k; i<=n; i++) {
        ans = max(ans, s[i]-s[i-k]);
    }

    cout << fixed << setprecision(15) << ans << endl;
    
    return 0;
}