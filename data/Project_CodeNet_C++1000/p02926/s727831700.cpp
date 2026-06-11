#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
#include <list>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <tuple>

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i <= (n); i++)
#define show(a, n) rep(i,n) {cout<<a[i]<<' ';} cout<<endl;

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<long long, long long> pll;

const int INF = 1 << 30;
const long long INFL = 1LL << 62;
const int MOD = 1000000007;
const int MAX = 100000;
const int N = 100010;

typedef long double ld;
typedef tuple<ld, ld, ld> tup;
const ld pi = acos(-1);

int main() {
	cout << fixed << setprecision(30);
	int n;
	cin >> n;
	vector<tup> v;
	rep(i, n) {
		ld x, y, arg;
		cin >> x >> y;
		if(x == 0.0 && y >= 0.0) {
			arg = pi / 2.0;
		}
		else if(x == 0.0 && y < 0.0) {
			arg = -pi / 2.0;
		}
		else {
			arg = atan(y / x);
			if(x < 0.0) arg += pi;
		}
		v.push_back(tup(arg, x, y));
	}
	sort(v.begin(), v.end());
	ld ans = 0.0;
	for(int i = 0; i < n; i++) {
		ld tmp_x = get<1>(v[i]);
		ld tmp_y = get<2>(v[i]);
		ans = max(sqrt(pow(tmp_x, 2.0) + pow(tmp_y, 2.0)), ans);
		for(int j = 1; j <= n - 1; j++) {
			tmp_x += get<1>(v[(i + j) % n]);
			tmp_y += get<2>(v[(i + j) % n]);
			ans = max(sqrt(pow(tmp_x, 2.0) + pow(tmp_y, 2.0)), ans);
		}
	}
	cout << ans << endl;
}
