#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>

const int mod = 2019;
const int INF = 1e16;
int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	rep(i, n) {
		cin >> a[i];
	}
	ll sum(0);
	rep(i, n) {
		sum += a[i];
	}
	ll sum1(0);
	rep(i, n) {
		if (i % 2 == 1) {
			sum1 += 2 * a[i];
		}
	}
	vector<int>x(n);
	x[0] = sum - sum1;
	rep(i, n-1) {
		x[i + 1] = 2 * (a[i] - x[i] / 2);
	}
	rep(i, n) {
		cout << x[i] << " ";
	}
	return 0;
}