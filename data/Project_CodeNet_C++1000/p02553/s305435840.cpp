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
    Int a, b, c, d;
    cin >> a >> b >> c >> d;
    Int ans = max({a * c, b * d, a * d, b * c});
    cout << ans << endl;
}