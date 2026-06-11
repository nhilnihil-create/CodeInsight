#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define all(x) (x).begin(),(x).end()
#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define isYES(x) printf("%s\n",(x) ? "YES" : "NO")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define isYes(x) printf("%s\n",(x) ? "Yes" : "No")
#define isIn(x,y,h,w) (x >= 0 && x < h && y >= 0 && y < w)
#define int long long
#define debug(var) cout << "[" << #var << "] " << var << endl
//using ll = long long;

const int INF=1e+18;
const double EPS=1e-9;
const int MOD=998244353;

signed main() {
    int n, a, b;
    cin >> n >> a >> b;

    if ((b-a) % 2 == 0) {
        cout << (b-a)/2 << endl;
        exit(0);
    }

    int result = 0;
    if (a-1 <= n-b) {
        result += a;
        result += (b-a-1)/2;
        cout << result << endl;
        exit(0);
    } else {
        result += n-b+1;
        result += (n-a-(n-b+1))/2;
        cout << result << endl;
        exit(0);
    }
}