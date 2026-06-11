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
	int n;
	cin >> n;
	vector<int>a(n), b(n);
	rep(i, n) {
		cin >> a[i] >> b[i];
	}
	vector<P>c(n), d(n);
	rep(i, n) {
		c[i].first = b[i];
		c[i].second = a[i];
	}
	sort(c.begin(), c.end());
	int time(0);
	rep(i, n) {
		time += c[i].second;
		if (time > c[i].first) {
			//cout << c[i].first << " " << c[i].second;
			cout << "No";
			return 0;
		}
		
	}
	cout << "Yes";
	return 0;
}