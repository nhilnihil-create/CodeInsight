#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000LL;
constexpr auto MOD = 1000000007;

int main() {
	
	ll a, b, c;
	cin >> a >> b >> c;
	bool ok = false;
	if (c - a - b > 0 && 4 * a * b < (c - a - b) * (c - a - b))ok = true;
	cout << (ok ? "Yes" : "No") << endl;

}