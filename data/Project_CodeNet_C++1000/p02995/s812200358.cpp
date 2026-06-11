#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = j; i < (int)n; ++i)
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;
using namespace std;

ll gcd(ll a, ll b) {
    return (b == 0 ? a : gcd(b, a % b));
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
    ll a, b, c, d; cin >> a >> b >> c >> d;

    --a;
    ll l = c / gcd(c, d) * d;
    ll e = b - b / c - b / d + b / l;
    ll f = a - a / c - a / d + a / l;
    cout << e - f << endl;
	return 0;
}
