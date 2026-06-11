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
int main() {
	int n;
	cin >> n;
	vector<int>a(n);
	rep(i, n) {
		int j(i);
		while (j < n) {
			a[j] += 1;
			j += (i + 1);
		}
	}
	ll sum(0);
	rep(i, n) {
		//cout << a[i] << endl;
		sum += ll(i + 1) * ll(a[i]);
	}
	cout << sum;
	return 0;
}