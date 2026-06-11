#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
#define V vector
typedef V<int> vi;
typedef V<vi> vvi;
typedef long long ll;
typedef pair<int, int> P;
constexpr auto INF = INT_MAX / 2;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int n;
	cin >> n;
	vi x(n), y(n);
	rep(i, n)cin >> x[i] >> y[i];

	map<P, int> mp;

	rep(i, n)rep(j, n) {
		if (i == j)continue;
		mp[make_pair(x[i] - x[j], y[i] - y[j])]++;
	}

	int mx = 0;
	for (auto x : mp)mx = max(mx, x.second);

	cout << n - mx << endl;

}