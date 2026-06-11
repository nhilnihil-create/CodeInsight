#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<functional>
#include<math.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pf(n) printf("%d\n",n)
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1001001001;
const double PI = acos(-1);

int main() {
	int n;
	cin >> n;
	map<int, int> d;
	int mx = 0;
	int mi = 1001001;
	rep(i, n) {
		int D;
		cin >> D;
		mx = max(mx, D);
		mi = min(mi, D);
		d[D]++;
	}
	vector<int> a(mx + 1, 0);
	a[1] += d[1];
	for (int i = 2; i <= mx; i++) {
		a[i] += d[i] + a[i - 1];
	}
	int ans = 0;
	for (int i = 1; i <= mx; i++) {
		if (a[i] == n / 2) ans++;
	}
	cout << ans << endl;

	return 0;
}