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
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	map<int, int> mp;
	rep(i,n) mp[a[i]]++;

	vector<int> v(1000001);
	ll ans = 0;
	for (auto p: mp) {
		int x = p.first;
		if (p.second > 1) v[x] = 1;
		for (int j = 2 * x; j <= 1000000; j += x) {
			v[j]++;
		}
		if (v[x] == 0) ans++;
	}
	cout << ans << endl;
}