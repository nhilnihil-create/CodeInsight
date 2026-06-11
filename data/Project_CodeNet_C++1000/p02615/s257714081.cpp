#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#define ran(x) (x).begin(),(x).end()
using namespace std;
int main() {
	int64_t n,ans=0;
	cin >> n;
	vector<int64_t> a(n);
	for(int64_t i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(ran(a));
	reverse(ran(a));
	for(int64_t i = 1; i < n; ++i) {
		ans += a[i / 2];
	}
	cout << ans << endl;
}