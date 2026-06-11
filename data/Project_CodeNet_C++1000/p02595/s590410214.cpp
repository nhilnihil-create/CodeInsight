#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define MOD 1000000007
#define MOD2 998244353
#define INF MOD
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

int main() {
    int n;
    Int d;
    cin >> n >> d;
    int ans = 0;
    rep(i,n) {
        Int x, y;
        cin >> x >> y;
        ans += x*x + y*y <= d*d;
    }
    cout << ans << endl;
}