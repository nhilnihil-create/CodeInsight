#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n, sum = 0, ans = 0, ans2 = 0; cin >> n;
	vector<int> x(n);
	for (int i = 0; i < n; i++) {
		cin >> x.at(i);
		sum += x.at(i);
	}
	int ave = sum / n;
	int ave2 = sum / n + 1;
	for (int i = 0; i < n; i++) {
		ans += (x.at(i) - ave) * (x.at(i) - ave);
	}
	if (sum % n == 0) {
		cout << ans << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		ans2 += (x.at(i) - ave2) * (x.at(i) - ave2);
	}
	cout << min(ans, ans2) << endl;
}