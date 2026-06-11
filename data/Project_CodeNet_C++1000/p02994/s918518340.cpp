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

int main() {
	int n, l;
	cin >> n >> l;
	vector<P>a(n);
	int sum(0);
	rep(i, n) {
		a[i].first = abs(i + l);
		a[i].second = (i + l);

		sum += i + l;
	}
	sort(a.begin(), a.end());
	sum -= a[0].second;
	cout << sum;
	return 0;

}