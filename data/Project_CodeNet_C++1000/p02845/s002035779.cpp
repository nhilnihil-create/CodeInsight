#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef pair<int, int> P;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
vi dy = { 0,0,1,-1 };
vi dx = { 1,-1,0,0 };
constexpr auto INF = INT_MAX/2;
constexpr auto MOD = 1000000007;



int main() {
	int n;
	cin >> n;
	vi a(n);
	rep(i, n)cin >> a[i];

	int c0 = 0, c1 = 0, c2 = 0;
	ll ans = 1;

	rep(i, n) {
		int hoge = 0;
		if (a[i] == c0)hoge++;
		if (a[i] == c1)hoge++;
		if (a[i] == c2)hoge++;

		ans *= hoge;ans %= MOD;

		if (a[i] == c0) { c0++;continue; }
		if (a[i] == c1) { c1++;continue; }
		if (a[i] == c2) { c2++;continue; }
	}

	cout << ans << endl;

}