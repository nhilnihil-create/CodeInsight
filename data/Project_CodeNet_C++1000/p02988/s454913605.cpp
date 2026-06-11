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
typedef tuple<int, int, int> T;
constexpr auto INF = INT_MAX >> 1;
constexpr auto LINF = 5000000000000000LL;
constexpr auto MOD = 1000000007;

int main() {

	int n;
	cin >> n;
	vi p(n);
	rep(i, n)cin >> p[i];
	int ans = 0;
	rep(i, n - 2) {
		if (p[i + 2] > p[i + 1] && p[i] < p[i + 1])ans++;
		if (p[i + 2] < p[i + 1] && p[i] > p[i + 1])ans++;
	}

	cout << ans << endl;

}