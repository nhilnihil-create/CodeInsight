#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
P arms[100010]; 
int main() {
	int n;
	cin >> n;

	int x, l;
	rep(i,n) {
		cin >> x >> l;
		arms[i] = {x+l,x-l};
	}
	sort(arms,arms+n);

	int ans = 0;
	int end = arms[0].second;
	rep(i,n) {
		if (arms[i].second >= end) {
			ans++;
			end = arms[i].first;
		}
	}
	cout << ans << endl;
	return 0;
}