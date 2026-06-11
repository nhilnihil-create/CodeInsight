#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define P pair<int,int>
#define PI 3.141592653589793
const int INF = 1001001001;

int main() {
	int n;
	cin >> n;
	vector<pair<ll,ll>> a(n);
	rep(i, n) {
		int x,l;
		cin >> x >> l;
		a[i].first = x + l;
		a[i].second = x - l;
	}
	sort(a.begin(), a.end());
	int ans = 1;
	ll now = a[0].first;
	rep(i, n) {
		if (i == 0)continue;
		if (now <= a[i].second) {
			now = a[i].first;
			ans++;
		}
	}
	cout << ans << endl;
}
