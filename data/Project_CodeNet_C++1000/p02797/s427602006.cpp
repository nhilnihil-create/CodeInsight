#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k, s;
	cin >> n >> k >> s;
	vector<int> a(n);
	if (s == 1000000000) {
		rep(i, k) a[i] = s;
		for (int i = k; i < n; ++i) a[i] = 1;
		rep(i, n) cout << a[i] << (i == n - 1 ? "\n" : " ");
	}
	else {
		rep(i, k) a[i] = s;
		for (int i = k; i < n; ++i) a[i] = s + 1;
		rep(i, n) cout << a[i] << (i == n - 1 ? "\n" : " ");
	}
	return 0;
}
