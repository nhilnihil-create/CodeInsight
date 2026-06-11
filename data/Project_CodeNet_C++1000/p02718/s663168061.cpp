#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	int sum = 0;
	rep(i, n) {
		cin >> a[i];
		sum += a[i];
	}
	int cnt = 0;
	rep(i, n) {
		if (a[i] * 4 * m >= sum) cnt++;
	}
	if (cnt >= m) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}