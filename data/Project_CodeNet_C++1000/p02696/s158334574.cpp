#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
	ll a, b, n;
	cin >> a >> b >> n;
	ll ans = floor((double) a / b * min(b - 1, n));
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}