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

int main() {
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j += i) {
			v[j]++;
		}
	}
	ll ans = 0;
	for (int i = i; i <= n; i++) {
		ans += (ll) i * v[i];
	}
	cout << ans << endl;
}