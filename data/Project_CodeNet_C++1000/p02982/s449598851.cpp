#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define P pair<int,int>
#define PI 3.141592653589793
const int INF = 1001001001;
const ll MX = 1e18;
const int mod = 1000000007;
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

int main() {
	int n, d;
	cin >> n >> d;
	vector<vector<int>> a(n, vector<int>(d));
	rep(i, n)rep(j, d) cin >> a[i][j];

	int ans = 0;
	rep(i, n)rep(j, i) {
		int s = 0;
		rep(k, d) {
			s += (a[i][k] - a[j][k]) * (a[i][k] - a[j][k]);
		}
		int sq = sqrt(s);
		if (sq * sq == s)ans++;
	}
	cout << ans << endl;
}